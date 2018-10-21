#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int T;

// 테트로노미오의 회전 및 대칭 된 모든 도형들을 노가다로 해서 구했다.
// 이걸 이렇게 말고 더 쉽게 할 수 있는 방법이 없을 까

// vector<vector<pair<int, int>> getTetromino(const vector<pair<int, int>> &tmp)
int MOVE[19][4][2] = {
        {
                {0, 0}, {0,1}, {0, 2}, {0,3}
        },
        {
                {0, 0}, {1,0}, {2, 0}, {3,0}
        },

        {
                {0, 0}, {0, 1}, {1, 0}, {1,1}
        },
//
        {
                {0,0}, {1,0}, {2,0}, {2,1}
        },
        {
                {0,0}, {1,0}, {2,0}, {2,-1}
        },
        {
                {0,0}, {1,0}, {2,0}, {0,1}
        },
        {
                {0,0}, {0,1}, {1,1}, {2,1}
        },
        {
                {0,0}, {1,0}, {1,1}, {1,2}
        },
        {
                {0,0}, {1,0}, {1,-1}, {1,-2}
        },
        {
                {0,0}, {0,1}, {0,2}, {1,0}
        },
        {
                {0,0}, {0,1}, {0,2}, {1,2}
        },
//

        {
                {0,0}, {1,0}, {1,1}, {2,1}
        },
        {
                {0,0}, {1,0}, {1,-1}, {2,-1}
        },
        {
                {0,0}, {0,1}, {1,1}, {1,2}
        },
        {
                {0,0}, {1,0}, {0,1}, {1,-1}
        },
        //
        {
                {0,0}, {0,1}, {0,2}, {1,1}
        },
        {
                {0,0}, {1,0}, {2,0}, {1,1}
        },
        {
                {0,0}, {0,1}, {0,2}, {-1,1}
        },
        {
                {0,0}, {1,0}, {2,0}, {1,-1}
        }
};

int N;
int M;

int arr[501][501];

bool is_valid(int r, int c){
    return (r<N and r >= 0) and (c >= 0 or c < M);
}
int getSum(int count){
    // MOVE[count]대해
    int best = -1;
    for(int r = 0; r < N; ++r){
        for(int c = 0 ; c < M; ++c){
            int tmp = 0;
            bool flag= true;
            for(int t = 0; t < 4; ++t){
                int candr= r+MOVE[count][t][0];
                int candc= c+MOVE[count][t][1];
                if(is_valid(candr, candc)) tmp += arr[candr][candc];
                else {
                    flag = false;
                    break;
                }
            }
//            cout<<tmp<< flag << endl;

            if(flag)best = max(best, tmp);

        }
    }
    return best;

}

int main() {
    freopen("../input", "r", stdin);
    cin>>T;
    for(int t = 0 ; t < T; ++t ){
        cin >> N; cin >> M;
        memset(arr, 0, sizeof(int) * 501 * 501);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                int tmp = 0; cin >> tmp;
                arr[r][c] = tmp;
            }
        }

        int best = -1;
        for(int i = 0 ; i < 19; ++i){
            best = max(best, getSum(i));
        }
        cout << best << endl;

    }











    return 0;
}