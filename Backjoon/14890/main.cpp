#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;



int T;
int N;
int L;
vector<vector<int>> board;
vector<vector<bool>> check[2];



// 조건하나 빠져먹음. 문제의 모든 조건들이 잘 구현되었는지 꼭 1 to 1 체크 필요
/*
 *
 * 경사로를 놓은 곳에 또 경사로를 놓는 경우 -> 이걸 빠져먹었음
 * 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
 * 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
 * 경사로를 놓다가 범위를 벗어나는 경우
 * 틀린이유 : c쪽에 *delta_height가 들어있지 않았음..
 * 이거도 원래 코드에서 자료를 추가할 때 업데이트를 제대로 다 안해서 생긴 문제
 */

int MOVE[2][2] = {
                {0, 1},
                {1, 0}
};



bool is_in_bound(int r, int c){
    // (r, c)가 (0, 0) 부터 (N-1, N-1) 사이에 있는지
    return (r >= 0 and r < N) and (c >= 0 and c < N);
}
bool is_valid(int r, int c, int dir, int delta_height){
    // (r, c)부터 , dir방향으로 L개가 모두 유효하면 return true
    for(int i = 0; i < L; ++i){
        if(is_in_bound(r + MOVE[dir][0] * i*delta_height, c + MOVE[dir][1] * i*delta_height)) continue;
        else return false;
    }
    return true;

}
bool is_same_height(int r, int c, int dir, int delta_height){
    int standard = board[r][c];
    for(int i = 0; i < L; ++i){
        int target = board[r + MOVE[dir][0] * i*delta_height][c + MOVE[dir][1] * i*delta_height];
        if(target != standard) return false;
    }
    return true;
}
bool is_used_slope(int r, int c, int dir, int delta_height){
    for(int i = 0; i < L; ++i){
        int ridx = r + MOVE[dir][0] * i*delta_height;
        int cidx = c + MOVE[dir][1] * i*delta_height;
        bool target = check[dir][ridx][cidx];
        if(target) return true;
    }
    return false;


}
void check_slope(int r, int c, int dir, int delta_height){
    for(int i = 0; i < L; ++i){
        check[dir][r + MOVE[dir][0] * i*delta_height][c + MOVE[dir][1] * i*delta_height]
        = true;
    }
}

int solve(int r, int c, int rem, int dir){
//    cout << r << " " << c << " " << rem << " " << MOVE[dir][0] << " " <<MOVE[dir][1]<<endl;
    int nextr = r + MOVE[dir][0];
    int nextc = c + MOVE[dir][1];

    if(not is_in_bound(nextr, nextc))return rem;
    int height_c = board[r][c];
    int height_n = board[nextr][nextc];
    if(abs(height_n- height_c) > 1) return rem;
    if(height_n == height_c)  return solve(nextr, nextc, rem+1, dir);

    // 경사로 설치하는 경우

    int delta = height_c- height_n;

    if(height_n == height_c + 1){
        // 다음거가 높이 1이 높은 경우
        // [current]부터 뒤로 연속한 L개가 모두 유효한 것인가?
        // 유효하지 않다면 return rem;
        if(not is_valid(r, c, dir, delta)) return rem;
        //유효하다면
        // 1) 이전에 슬로프가 놓인 것이 단 하나라도 있는가?
        if(is_used_slope(r, c, dir, delta)) return rem;
        // 2) 모두 같은 높이 인가?
        if(not is_same_height(r, c, dir, delta)) return rem;
        else{
            //(r, c) 부터 역으로 L개에 slope를 놔둔다.
            check_slope(r, c, dir, delta);
            return solve(nextr, nextc, rem+1, dir);
        }
    }else{ // 현재가 앞에꺼보다 높이 1 높은 경우
        //next부터 연속한 L개가 모두 유효한 것인가?
        if(not is_valid(nextr, nextc, dir, delta))return rem;
        //유효하다면
        // 1) 모두 같은 높이인가?
        if(not is_same_height(nextr, nextc, dir, delta)) return rem;
        if(is_used_slope(nextr, nextc, dir, delta)) return rem;
        else{
            check_slope(nextr, nextc, dir, delta);
            nextr += MOVE[dir][0] * (L-1);
            nextc += MOVE[dir][1] * (L-1);
            return solve(nextr, nextc, rem+L, dir);
        }
    }
}
int main() {
    freopen("../input", "r" , stdin);
    cin >> T;
    for(int t = 0; t < T;++t){
        cin >> N; cin >> L;

        board = vector<vector<int>>(N, vector<int>(N, 0));
        for(int i = 0; i < 2; ++i){
            check[i].clear();
            check[i] = vector<vector<bool>>(N, vector<bool>(N, false));
        }

        for(int r = 0; r < N; ++r)for(int c =0 ; c < N; ++c)
            cin>>board[r][c];

        int ans = 0;

        for(int r = 0; r < N; ++r){
            int tmp = solve(r, 0, 0, 0);
            if(tmp == N-1) ans++;
        }

        for(int c = 0; c < N; ++c){
            int tmp = solve(0, c, 0, 1);
            if(tmp == N-1) ans++;
        }
        cout<<ans<<endl;
    }


    return 0;
}