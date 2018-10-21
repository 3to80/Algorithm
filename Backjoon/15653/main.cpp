#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

int T;
int N;
int M;

char board[10][10];
int checkBoard[10][10][10][10];

typedef pair<int, int> point;


void print(){
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < M; ++c){
            cout << board[r][c];
        }
        cout<<endl;
    }

}

void print(const point &red, const point &blue){
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < M; ++c){
            if(r == red.first and c == red.second){
                cout << 'R';
            }else if(r == blue.first and c == blue.second){
                cout << 'B';
            }
            else cout << board[r][c];

        }
        cout<<endl;
    }

}


int MOVE[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1,0}
};



/*
 * move2(target)
 * 1) target == # return target -(dr, dc)
 * 2) target == . regurn move2(target + (dr, dc))
 * 3) target == blue return target -(dr, dc)
 * 4) target == O return target
*/

point next(point marble, int dir);
point before(point marble, int dir);
bool cmp(point a, point b);
point moveRed(point target, const point &red, const point &blue, int dir){
    if(target == red) moveRed(next(target, dir), red, blue, dir);
    if(board[target.first][target.second] == '#') return before(target, dir);
    if(board[target.first][target.second] == '.') return moveRed(next(target, dir), red, blue, dir);
    if(cmp(target, blue)) return before(target, dir);
    if(board[target.first][target.second] == 'O') return target;
}


point move(const point& target, const point &red, const point &blue, int dir){
    // red를 이동시킨
    point ret = make_pair(target.first+MOVE[dir][0],
                          target.second+MOVE[dir][1]);
    // ret이 멈추는 경우
    // 1. ret의 값이 #인 경우, ret -= (dr, dc)하고 종료
    // 2. ret의 값이 B인 경우, ret -= (dr, dc)하고 종료
    // 3. ret의 값이 O인 경우, 종료
    // 4. ret의 값이 .인 경우, 반복


    while(true){
        char ch = board[ret.first][ret.second];
        if(ch == 'O') break;
        else if(ch == '#'){
            ret.first -= MOVE[dir][0];
            ret.second-= MOVE[dir][1];
            break;
        }
        else if(ret.first == blue.first and ret.second == blue.second){
            ret.first -= MOVE[dir][0];
            ret.second-= MOVE[dir][1];
            break;
        }
        else if(ret.first == red.first and ret.second == red.second){
            ret.first -= MOVE[dir][0];
            ret.second-= MOVE[dir][1];
            break;
        }

        else{
            ret.first += MOVE[dir][0];
            ret.second += MOVE[dir][1];
        }

    }
    return ret;
}

bool is_O(const point &marble){

    return board[marble.first][marble.second] == 'O';

}
int getCheckBoard(const point &red, const point &blue){
    return checkBoard[red.first][red.second][blue.first][blue.second];
}

void setCheckBoard(const point &red, const point &blue, int val){
    checkBoard[red.first][red.second][blue.first][blue.second] = val;
}


int getCheckBoard(const pair<point, point> &state){
    return getCheckBoard(state.first, state.second);
}

int solve(const point &R, const point &B){
    // R, B에 대해 여러차례 시뮬레이션을 하고 R만 나갈 수 있으면 최소 횟수를 반환한다.
    int ret= -1;

    deque<pair<point, point>> deq;
    deq.emplace_back(make_pair(R, B));
    setCheckBoard(R, B, 1);


    while(not deq.empty()){
        auto target = deq.front();
        deq.pop_front();

//        print(target.first, target.second);
        // target이 끝났는지를 조사한다.
        // 1) B가 O에 도달한 경우
        // 2) R이 O에 있고 R이 나가면 B가 그자리에 오는 경우
        // - direction을 무는 방법. 그리고 애시당초 생성할떄 이런 경우는 넣지 않는 방
        // 3) R이 O에 있고 R이 나가도 B가 들어오지 않는 경우
        if(is_O(target.second))continue;
        if(is_O(target.first)) return getCheckBoard(target);


        //target이 끝나지 않았다면

        for(int dir = 0; dir < 4; ++dir){
            // DIR에 대해 이동시킨다.
            int before = getCheckBoard(target);
            point beforeRed=target.first;
            point beforeBlue=target.second;
            // move
            point newRed = move(beforeRed, beforeRed, beforeBlue, dir);
            point newBlue = move(beforeBlue, newRed, beforeBlue, dir);
            //newRed가 도착했다면
            // newRed의 dir방향 옆으로 .이 있으면
            if(not is_O(newRed) and board[newRed.first+MOVE[dir][0]][newRed.second+MOVE[dir][1]] == '.')
                newRed = move(newRed, newRed, newBlue, dir);

            // Red와 Blue가 dir 방향에 대해 붙어 있다면 걸러야 한다.
            // Red가 O의 위치에 있고 Red-dr, Red - dc 가 blue랑 같으면 거른다.
            if((is_O(newRed)) and (newRed.first-MOVE[dir][0] == newBlue.first)
            and (newRed.second - MOVE[dir][1] == newBlue.second)) continue;

            if(getCheckBoard(newRed, newBlue) == 0){
                //아직 나오지 않은 모양이면 추가한.다
                setCheckBoard(newRed, newBlue, before+1);
                deq.emplace_back(make_pair(newRed, newBlue));
            }


        }



    }



    return ret;



}
int main() {
    freopen("../input", "r", stdin);
    cin>>T;
    for(int t = 0; t < T; ++t){
        cin >> N; cin >> M;
        memset(board, '#', sizeof(char) * 100);
        memset(checkBoard, 0, sizeof(int) * 10000);

        point R;
        point B;
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                cin >> board[r][c];
                if(board[r][c] == 'R'){
                    R=make_pair(r,c);
                    board[r][c]='.';
                }
                else if(board[r][c] == 'B'){
                    B=make_pair(r,c);
                    board[r][c]='.';
                }
            }
        }

        int ret = solve(R, B);
        if(ret == -1) cout << -1 << endl;
        else cout<< ret-1 << endl;







    }


    return 0;
}