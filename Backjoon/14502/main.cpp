#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int T;
int N;
int M;
//
//
//
//
vector<vector<int> > board;
typedef pair<int, int> point;
vector<pair<int, int> > virus;
vector<vector<bool>> visited;
int best = -1;

int MOVE[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}

};

bool is_in_bound(int r, int c){
    return r >=0 and r < N and c >= 0 and c < M;
}
vector<point> makeLocations(){
    vector< point > locations;

    for(int r = 0 ; r < N; ++r){
        for(int c = 0 ; c < M; ++c){
            if(board[r][c] == 0)
                locations.emplace_back(make_pair(r,c));
        }
    }
    return locations;

}

//특정위치의 바이러스에서 시작해 주변을 증식시킨다.
void paint(vector<vector<int>> &ret, point virus){
    for(int i = 0; i < 4; ++i){
            int r = virus.first+MOVE[i][0];
            int c = virus.second+MOVE[i][1];
            if(not is_in_bound(r, c))continue;
            if(visited[r][c])continue;
            if(ret[r][c] == 0){
                visited[r][c] = true;
                ret[r][c] = 2;
                paint(ret, make_pair(r, c));
            }
    }

}

vector<vector<int>> inflate(const vector<point> &pick){
    // pick에 벽을 만들었을 때
    vector<vector<int>> ret(board);
    visited = vector<vector<bool>>(N, vector<bool> (M, false));
    for(auto i : pick)
        ret[i.first][i.second] = 1;
    // 현재 2인 위치 들에 대해 증식을 시작한다.
    for(auto v : virus){
        //virus를 증식시킨다.
        paint(ret, v);

    }

    return ret;
}
//
int getSafe(const vector<vector<int>> &b){
    int ans = 0;
    for(int r = 0 ; r < N ; ++r){
        for(int c = 0; c < M ; ++c){
            if(b[r][c] == 0) ans ++;
        }
    }
    return ans;
}

// combination 구현하는 거
void solve(int idx, vector<point> &pick, const vector<point> &locations){
    if(pick.size() == 3){

        vector<vector<int>> situation = inflate(pick);
        int tmp = getSafe(situation);
        best = max(best, tmp);
        return;
    }

    // 처음에 A라는 값으로 해서 다 진행을 시키려고 했다.
    // 근데 구현하ㅏ가 어 A가 아닌 B라는 값으로 하는게 맞는 거 같은거야
    // 그러면 이 때 A란 값을 B로 바꾸면 바꿔지는 모든 값들을 다 신경써야된다.
    // 근데 이걸 엄청 대충 생각하는거 같다. 그래서 이런 문제가 계속 발생하는 거 같다.
    for(int nextstart = idx; nextstart < locations.size(); ++nextstart){
        if(locations.size()- nextstart < (3-pick.size()))break;
        pick.emplace_back(locations[nextstart]);
        solve(nextstart+1, pick, locations);
        pick.pop_back();
    }
}
int main() {
    freopen("../input", "r", stdin);
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> N; cin >> M;
        board.clear();
        virus.clear();
        best = -1;
        virus = vector<point>();
        board = vector<vector<int>>(N, vector<int> (M, 0));


        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                cin >> board[r][c];
                if(board[r][c] == 2) virus.emplace_back(make_pair(r, c));
            }
        }
        vector<pair<int, int>> locations = makeLocations();


        vector<point> pick;
        solve(0, pick, locations);
        cout << best<<endl;


    }


    return 0;
}