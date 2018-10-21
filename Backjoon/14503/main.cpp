#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;
typedef pair<int, int> point;

vector<vector<bool>> freshmap;
vector<vector<int>> board;
int N;
int M;

void clean(const point &loc){
    freshmap[loc.first][loc.second] = true;
}
point rotateLeft(const point &dir){
    return make_pair(-1 * dir.second, dir.first);
}
point move(const point &loc, const point &dir, int pad){
    return make_pair(loc.first + dir.first * pad, loc.second + dir.second * pad);
}
bool is_wall(const point &loc){
    return board[loc.first][loc.second] == 1;
}
bool is_clean(const point &loc){
    return freshmap[loc.first][loc.second] == true;
}
int getCount(){
    int ans = 0;
    for(int r =0 ; r < N; ++r)for(int c =0 ; c < M; ++c)if(freshmap[r][c])++ans;
    return ans;
}

void solve(const point& loc, const point &dir){

    clean(loc);
    point nextdir(dir);
    point cand(loc);
    vector<pair<point, point>> ans;
    for(int i = 0 ; i< 4; ++i){
        nextdir = rotateLeft(nextdir);
        cand = move(loc, nextdir, 1);
        if(not is_wall(cand) and not is_clean(cand)){
            ans.emplace_back(make_pair(cand, nextdir));
            break;
        }
    }

    if(not ans.empty()){
        solve(ans.front().first, ans.front().second);
        return;
    }
    else{
    point back = move(loc, dir, -1);
        if(is_wall(back)) return;
        else solve(back, dir);
    }
}



int main() {
    freopen("../input", "r", stdin);
    point current;
    point dir;

    cin >> N; cin >> M;
    int r; cin >> r; int c; cin>>c;
    current=make_pair(r, c);
    int d; cin>> d;
    switch (d){
        case 0: // 북
            dir = make_pair(-1, 0);
            break;
        case 1: // 동
            dir = make_pair(0, 1);
            break;
        case 2:
            dir = make_pair(1, 0);
            break;
        case 3:
            dir = make_pair(0, -1);
            break;
        default:
            cout<<"error"<<endl;
            break;
    }
    board = vector<vector<int>>(N, vector<int>(M, 0));
    freshmap= vector<vector<bool>>(N, vector<bool>(M, false));
    for(int r = 0; r < N; ++r)for(int c = 0; c < M; ++c)cin >> board[r][c];
    solve(current, dir);
    int ret = getCount();
    cout << ret << endl;


    return 0;
}