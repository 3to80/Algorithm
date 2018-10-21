#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int T; // testcase 여기서만 쓴다.
int N;
int M;

vector<vector<int>> board;
vector<vector<int>> aux;
typedef pair<int, int> point;
vector<point> locations;

void print(vector<vector<int>> board){
    for(auto i : board){
        for(auto j : i){
            cout << j << " ";
        }
        cout<<endl;
    }
}

int best = 987654321;

int get_nonseen(){
    // 현재 aux에서 놓을 수 있는 개수를 구한다. 0인 것들의 개수를 구한다.
    int ret = 0;
    for(int r= 0; r < N; ++r)for(int c= 0; c < M; ++c)
        if(aux[r][c] ==0) ++ret;
    return ret;
}

vector<vector<pair<int, int> > > MOVE[5];

bool check_boundary(const point &target){
    return (target.first>= 0 and target.first < N) and (target.second>= 0 and target.second< M);
}

void paint(point target, point d, vector<point> &save){
    //  -> aux를 업데이트하는데 보드안에 있고 6 만나기 전까지의 값들에 다 1씩 더한다. 이 때 더해지는 좌표들을 선택한다.

    // target이 바운더리에 들지 않으면 중단한다.
    // target이 만약 6이면 중단한다.
    if(not check_boundary(target)) return;
    if(board[target.first][target.second]==6) return;

    // 나머지 경우, aux에 1씩 다 더한다. 그리고 다음 진행을 한다.
    save.emplace_back(target);
    aux[target.first][target.second]++;
    paint(make_pair(target.first + d.first, target.second + d.second), d, save);
}

void rollback(vector<point> &save){
    for(auto i :save){
        aux[i.first][i.second]--;
    }

}

void solve(int idx){
    if(idx == locations.size()){
        // 현재 aux에서 사각의 개수를 구한다.
        int nonseen = get_nonseen();
        best = min(best, nonseen);
        return;
    }
    else{
        point target = locations[idx];
        int flag = board[target.first][target.second];

        // MOVE[flag-1] 에 대해
        for(int i = 0; i < MOVE[flag-1].size(); ++i){
            // MOVE[flag-1] [0] [1]에 대해 시도를 한다.
            vector<point> dir = MOVE[flag-1][i];
            // aux에 part에 대해 이동시킨다.
            vector<point> save;
            for(auto part: dir){
                // part에 대해 칠한다.
                paint(target, part, save);

            }
            // 특정방향에 놓는다.
            // -> aux를 update한다.
            solve(idx+1);
            // -> aux를 rollback 한다.
            // -> 이전에 저장한 좌표들에 대해 1씩 다 뺀다.
            rollback(save);

        }



    }



}


void preprocess(){

    point North(1, 0);
    point East(0, 1);
    point South(-1, 0);
    point West(0, -1);

    for(int m = 0; m <5; ++m) MOVE[m].clear();

    // 1일
    vector<point> tmp1;
    vector<point> tmp2;
    vector<point> tmp3;
    vector<point> tmp4;

    tmp1.emplace_back(North);
    tmp2.emplace_back(East);
    tmp3.emplace_back(South);
    tmp4.emplace_back(West);

    MOVE[0].emplace_back(tmp1);
    MOVE[0].emplace_back(tmp2);
    MOVE[0].emplace_back(tmp3);
    MOVE[0].emplace_back(tmp4);

    // 2
    tmp1.clear();
    tmp2.clear();
    tmp3.clear();
    tmp4.clear();

    tmp1.emplace_back(West);
    tmp1.emplace_back(East);
    tmp2.emplace_back(North);
    tmp2.emplace_back(South);

    MOVE[1].emplace_back(tmp1);
    MOVE[1].emplace_back(tmp2);


    // 3
    tmp1.clear();
    tmp2.clear();
    tmp3.clear();
    tmp4.clear();

    tmp1.emplace_back(North);
    tmp1.emplace_back(East);
    tmp2.emplace_back(East);
    tmp2.emplace_back(South);
    tmp3.emplace_back(South);
    tmp3.emplace_back(West);
    tmp4.emplace_back(West);
    tmp4.emplace_back(North);

    MOVE[2].emplace_back(tmp1);
    MOVE[2].emplace_back(tmp2);
    MOVE[2].emplace_back(tmp3);
    MOVE[2].emplace_back(tmp4);

    //4
    tmp1.clear();
    tmp2.clear();
    tmp3.clear();
    tmp4.clear();

    tmp1.emplace_back(North);
    tmp1.emplace_back(East);
    tmp1.emplace_back(South);

    tmp2.emplace_back(East);
    tmp2.emplace_back(South);
    tmp2.emplace_back(West);

    tmp3.emplace_back(South);
    tmp3.emplace_back(West);
    tmp3.emplace_back(North);

    tmp4.emplace_back(West);
    tmp4.emplace_back(North);
    tmp4.emplace_back(East);

    MOVE[3].emplace_back(tmp1);
    MOVE[3].emplace_back(tmp2);
    MOVE[3].emplace_back(tmp3);
    MOVE[3].emplace_back(tmp4);
    //5
    tmp1.clear();

    tmp1.emplace_back(North);
    tmp1.emplace_back(East);
    tmp1.emplace_back(South);
    tmp1.emplace_back(West);
    MOVE[4].emplace_back(tmp1);

}
int main() {


    preprocess();

    freopen("../input", "r", stdin);

    cin>>T;


    for(int t = 0; t < T; ++t){
        cin >> N; cin>> M;
        board = vector<vector<int>>(N, vector<int>(M, 0));
        aux = vector<vector<int>>(N, vector<int>(M, 0));
        locations.clear();
        best = 987654321;
        for(int r = 0; r < N; ++r)for(int c =0; c < M; ++c){
            cin >> board[r][c];
            if(board[r][c] ==0) continue;
            aux[r][c] = 1;
            // 1~ 5 이면 locations에 (r, c)를 넣는다.
            if(board[r][c] < 6)locations.emplace_back(make_pair(r, c));
        }

        solve(0);
        cout<<best << endl;





    }

    return 0;
}