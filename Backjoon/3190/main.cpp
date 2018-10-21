#include <iostream>
#include <stdio.h>
#include<queue>
#include <cstring>

using namespace std;

typedef pair<int, int> point;


deque<point> snake;

// (1, 1) 부터 (N, N)을 사용한다.
int board[101][101];
// 갈수 없는 곳은 0. 갈수 있는 곳은 1, 사과는 2, 뱀의 일부분은 3



struct MOVE{
    int time;
    char dir;
    MOVE(int t, char d):time(t), dir(d){};
};

deque<MOVE> move_info;
point head_dir;


int T;
int N;
int K; // 사과 개수
int L; // 뱀의 변환횟수

bool is_end(const point& newhead){
    //새로운 머리 좌표를 획득한다.
    /*
     * 조건1: 뱀의 머리가 자기 자신의 몸과 부딪히면 게임이 끝난다.
     * 조건2: 뱀이 벽과 부딪히면 게임이 끝난다. : 항상 머리부터 이동하기 때문에 머리만 보면 된다.
     */

    // 벽에 부딪힌경우
    if(board[newhead.first][newhead.second] == 0)return true;
    // 자기 몸과 부딪힌 경우
    if(board[newhead.first][newhead.second] == 3)return true;
    // 두가지 조건 외는 false 이다.
    return false;
}


point moveRight(const point& p){
    return make_pair(p.second, -p.first);
}
point moveLeft(const point& p){
    return make_pair(-p.second, p.first);
}

point makeNextDir(const point& curhead, const MOVE& info){
    // info와 현재 head_dir를 통해 head_dir을 갱신한다..
    // info의 글자가 L이면 왼쪽으로 회전시킨다.
    // info의 글자가 R이면 오른쪽으로 회전시킨다
    if(info.dir == 'L')return moveLeft(curhead);
    else return moveRight(curhead);
}

point makeNextHead(const point &head_dir, const point &currenthead){
    // current head와 head_dir을 통해 다음 nexthead의 좌표를 생성한다.
    return make_pair(currenthead.first + head_dir.first, currenthead.second + head_dir.second);
}


bool is_apple(const point& curhead){
    return board[curhead.first][curhead.second] == 2;
}


bool moveSnake(int time){
//    int &head_dir, deque<point> &snake, const deque<MOVE> &move_info, int time
// 뱀의 head가 이동못하는 곳에 도달했을 때 false를 리턴한다.
    /*
     * 1. 다음 머리 좌표와 방향을 만든다.
     * 1) move_info의 front()의 시간과 time이 다른 경우
     *  - 현재 head_dir대로 해서 좌표를 만든다.
     * 2) move_info와 back()의 시간이 time이 같은 경우
     *  - move_info.back()의 방향 정보와 head_dir를 통해 새로운 new_head_dir을 만든다.
     *  - 방향에 맞는 newhead를 만든다.*/
     if(time == move_info.front().time){
         // 회전해야 되는 경우
         head_dir = makeNextDir(head_dir, move_info.front());
//         cout<<"next head_dir";
//         print(head_dir);

         move_info.pop_front();
     }
     point nexthead = makeNextHead(head_dir, snake.back());

     /* 2. newhead 좌표에서 끝나는지 체크한다.
     * - 끝난다면 return false
      * */
     if(is_end(nexthead)) return false;
     /*
     * 3. newhead 좌표가 맞으니 사과를 먹는지 확인한다.
     *  - 사과가 있으면 아무 일도 일어나지 않는다.
     *  - 사과가 없으면 newhead.front()를 없앤다.
     *
     *  1) snake에 newHead의 좌표를 넣는다. (head_dir이 적절한지 확인해야 한다)
     *  2) board[snakeHead좌표] 에 사과가 있는지확인한다
     *      - 있으면 먼저 board(newHead)에 3을 넣는다.
     *      - 없으면 snake에서 꼬리를 없앤다.
     *          그리고 board(꼬리) = 1 을 한다.
     *
     * 끝나지 않았으니 return true 를 한다.
     */
     snake.emplace_back(nexthead);
     if(is_apple(nexthead)){
         board[nexthead.first][nexthead.second] = 3;
     }else{
         board[nexthead.first][nexthead.second] = 3;
         point tail = snake.front();
         board[tail.first][tail.second] = 1;
         snake.pop_front();
     }
     return true;
}


int main() {
    freopen("../input", "r" , stdin);
    cin>>T;
    for(int t = 0; t < T; ++t){
        // 자료 초기화
        memset(board, 0, sizeof(int) * 101 * 101);
        move_info.clear();
        snake.clear();
        // input 파일에서 값 넣기
        cin>>N;cin>>K;
        // 이번에 쓰는 영역은 1로 먼저 만들
        for(int r =1 ; r< N+1; ++r)
            for(int c =1 ; c < N+1; ++c)
                board[r][c] = 1;
        // 사과 넣기
        for(int k = 0; k < K; ++k){
            int r; int c;
            cin>>r; cin>> c;
            board[r][c] = 2;
        }
        // 뱀 시작 넣기
        board[1][1] = 3;
        head_dir= make_pair(0, 1);
        snake.emplace_back(make_pair(1,1));
//        head_dir 이 뱀 머리의 방향
//        snake.back()이 뱀 머리의 위치

        cin >> L;
        for(int l = 0; l < L; ++l){
            int tmp; char tmp_char;
            cin>> tmp; cin >> tmp_char;
            move_info.emplace_back(MOVE(tmp, tmp_char));
        }

        // input 확인 : ok
//        print();
//        print(move_info);

        // 현재 보드 상태에서 게임이 끝나는지를 확인한다.
        // is_end(deque<point> snake, head_dir)
        /*
         * 조건1: 뱀의 머리가 자기 자신의 몸과 부딪히면 게임이 끝난다.
         * 조건2: 뱀이 벽과 부딪히면 게임이 끝난다.
         */
        int time = 0;
        /*
         * 현재 보드 상태에서 게임이 끝나지 않는다면 뱀을 이동시킨다.
         * moveSnake(point &head_dir, deque<point> &snake, const deque<MOVE> &move_info, int time);
         * 현재 시간이 move_info의 back() 시간과 같다면 회전을 시킨다.
         * 현재 시간이 move_info의 back() 시간과 다르면 head_dir 방향 그대로 간다.
         */
        while(true){
//            cout<<"time" << time << " before " << endl;
//            print();
//            cout<<endl;

            bool flag = moveSnake(time);
            if(flag == false) break;
            else time++;
//            cout<<"time" << time << " after " << endl;
//            print();
//            cout<<endl;

        }

        cout<<time+1<<endl;






    }



    return 0;
}