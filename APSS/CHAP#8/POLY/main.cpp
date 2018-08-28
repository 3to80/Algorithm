#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const long long MOD = 10000000;


const long long MAX_LEN = 101;
long long DP[MAX_LEN][MAX_LEN];

long long solve(long long rem, long long upper_width){
    if(DP[rem][upper_width] != -1) return DP[rem][upper_width];

    long long ret = 0;
    if(rem == 0) return (DP[rem][upper_width] = 1);

    for(long long i = 1; i <= rem; ++i){
        ret += (solve(rem -i, i)%MOD) * (upper_width + i -1);
        if(ret > MOD) ret %= MOD;
    }
    return (DP[rem][upper_width] = ret);
}




long long solve(long long rem){
    long long ret = 0;
    for(long long i = 1; i <=rem; ++i)
        ret += solve(rem -i, i);
    return ret%MOD;
}


int main() {
//    std::cout << "Hello, World!" << std::endl;
    memset(DP,  -1, sizeof(long long) * MAX_LEN* MAX_LEN);

    cout << solve(92)<<endl;


    return 0;
}