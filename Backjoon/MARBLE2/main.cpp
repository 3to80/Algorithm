#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N; // 세로크기 : row
int M; // 가로크기 : col



vector<vector<int> > MOVE = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
};


pair<int, int> moveTo(pair<int, int> &marble, int dir){
    // marble를 dir 방향으로 하나 옮겼을 때 좌표를 return 한다.
    return make_pair(marble.first+MOVE[dir][0], marble.second+ MOVE[dir][1]);
}
int main() {
    freopen("../input", "r", stdin);


    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> N; cin >> M;
        char map[10][10];
        for(int n = 0; n < N; ++n)
            for(int m = 0; m < M; ++m)
                cin >> map[n][m];
        typedef pair<int, int> pi;

        pi red, blue, hole;
        for(int n = 0; n < N; ++n){
            for(int m = 0; m < M; ++m){
                char tmp = map[n][m];
                if(tmp == 'R') red=make_pair(n, m);
                else if(tmp == 'B') blue=make_pair(n, m);
                else if(tmp == 'O') hole=make_pair(n, m);

            }
        }

        deque<pair<pi, pi>> deq;
        int ans = -1;
        deq.push_front(make_pair(red, blue));
        int aux[10][10][10][10];
        memset(aux, -1, sizeof(int) * 10000);

        while(not deq.empty()){
            pi marble[2] =  {deq.front().first, deq.front().second};
            deq.pop_back();
            // base case
            if(marble[1] == hole) continue;
            if(marble[0] == hole){
                ans = aux[marble[0].first][marble[0].second][marble[1].first][marble[1].second];
                break;
            }
            if(aux[marble[0].first][marble[0].second][marble[1].first][marble[1].second]  >= 10) continue;
            // loop case
            for(int dir = 0; dir < 4; ++dir){
                pi next[2] = {marble[0], marble[1]};
                for(int j = 0; j < 2; ++j){
                    while(true){
                        if(map[next[j].first][next[j].second] == 'O') break;
                        pi cand = moveTo(next[j], dir);
                        if(map[cand.first][cand.second] == '#') break;
                        if(map[cand.first][cand.second] == 'O'){
                            next[j] = cand;
                            break;
                        }
                        if(cand == next[1-j]) break;
                        next[j] = cand;
                    }
                }
                if(aux[next[0].first][next[0].second][next[1].first][next[1].second] != -1) continue;
                aux[next[0].first][next[0].second][next[1].first][next[1].second] =
                        aux[marble[0].first][marble[0].second][marble[1].first][marble[1].second] + 1;
                deq.push_front(make_pair(next[0], next[1]));
            }
        }
        if(ans == -1) ans = -1;
        cout << ans << endl;


    }




    return 0;
}


