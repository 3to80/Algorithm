#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
int M;
vector<vector<int>> board;




typedef pair<int, int> point;

bool is_bound(point current){
    // current가 bound 안이면 true
    return (current.first >= 0 and current.first < N and current.second >= 0 and current.second < M);
}


int MOVE[3][2] = {
        {+1, 0},
        {0, +1},
        {+1, +1}
};


int ans[1001][1001];


int solveDP(point current){

    int &ret = ans[current.first][current.second];
    if(ret != -1) return ret;

    if(current.first == 0 and current.second == 0)return ret = board[0][0];
    int maxvalue= -1;

    for(int i = 0; i < 3; ++i){
        point before(current.first - MOVE[i][0], current.second - MOVE[i][1]);
        if(not is_bound(before))continue;
        maxvalue= max(maxvalue, solveDP(before));
    }

    return ret = (maxvalue+ board[current.first][current.second]);

}

int main() {
    freopen("../input", "r", stdin);
    cin>>T;

    for(int t = 0; t < T; ++t){
        cin >> N;cin>>M;
        memset(ans, -1, sizeof(int)*1001 * 1001);
        board = vector<vector<int>>(N, vector<int>(M, 0));
        for(int r = 0; r < N; ++r)for(int c = 0; c < M; ++c)
                cin >> board[r][c];

        cout<<solveDP(make_pair(N-1, M-1))<<endl;


    }






    return 0;
}