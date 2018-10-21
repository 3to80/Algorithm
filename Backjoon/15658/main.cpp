#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int N; // 수의 개수
int op_num[4] ={0}; // 가용연산자들의 개수
vector<int> number;

int maxval = -987654321;
int minval = 987654321;



int emulate(int ret, int op, int tidx){
    switch (op){
        case 0:
            return ret + number[tidx];
        case 1:
            return ret - number[tidx];
        case 2:
            return ret * number[tidx];
        case 3:
            return ret / number[tidx];
    }
}
void solve(int result, int pick){
    if(pick == N-1){
        maxval = max(maxval, result);
        minval = min(minval, result);
        return;
    }


    for(int op = 0; op < 4; ++op){
        // 연산자 개수가 0이면 못쓰니 넘긴다.
        if(op_num[op] == 0) continue;
        // op를 선택한다.
        op_num[op]--;
        solve(emulate(result, op, pick+1), pick+1);
        op_num[op]++;


    }





}
int main() {
    freopen("../input", "r" , stdin);

    cin >> N;
    number= vector<int>(N, 0);
    for(int n = 0; n < N; ++n) cin >> number[n];
    for(int i =0; i < 4; ++i) cin>>op_num[i];


    solve(number[0], 0);

    cout<<maxval<<endl<<minval;



    return 0;
}