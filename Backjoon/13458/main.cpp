#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int T;

typedef long long ll;
ll tmp;
int N;
ll B;
ll C;

ll arr[1000001];

int main() {
    freopen("../input", "r" , stdin);
    cin >>T;
    for(int t = 0; t < T; ++t){
        ll ans = 0;
        cin >> N;
        memset(arr, 0, sizeof(ll) * 1000001);
        for(int n = 0 ; n < N; ++n){
            cin >> arr[n];
        }
        cin>>B; cin>> C;

//        5
//        10 9 10 9 10
//        7 20


        for(int n = 0 ; n < N; ++n){
            ans += 1;

            arr[n]-= B;
            if(arr[n] > 0){
                ans += arr[n]/C;
                if(arr[n]%C != 0) ans += 1;
            }
        }


        cout<<ans<<endl;
    }


    return 0;
}