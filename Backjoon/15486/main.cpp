#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int T;
int N;

const int MAXN= 1500001;
int benefit[MAXN];
int cost[MAXN];
int aux[MAXN];


int solve(int i){
    // solve(i) : [i, N] 까지 남은 것들의 최대 값
    //base case
    // 더이상 선택할 수 없으면 0을 반환한다.
//    cout<< i << endl;
    int &ret = aux[i];
    if(ret != -1) return ret;

    if(i> N) return ret=0;
    if(i-1+cost[i] >= N+1){
        return ret=solve(i+1);
    }

    // loop case
    int pick = benefit[i] + solve(i+cost[i]);
    int nonpick = solve(i+1);
    return ret=max(pick, nonpick);

}

int main() {
    freopen("../input", "r", stdin);
    cin>>T;
    for(int t = 0; t < T; ++t){
        cin >> N;
        memset(benefit, 0, sizeof(int) * MAXN);
        memset(cost, 0, sizeof(int) * MAXN);
        memset(aux, -1, sizeof(int) * MAXN);

        for(int n = 0; n < N; ++n){
            cin >> cost[n+1]; cin>>benefit[n+1];
        }

        cout << solve(1)<<endl;




    }




    return 0;
}