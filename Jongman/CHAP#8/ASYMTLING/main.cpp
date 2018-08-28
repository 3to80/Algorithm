#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;



const long long MOD = 1000000007;
long long dp[101];




long long fill_Square(int n){
    if(dp[n] != -1)
        return dp[n];
    if(n == 1) return (dp[1] = 1);
    if(n == 2) return (dp[2] = 2);
    return (dp[n] = (fill_Square(n-1)%MOD + fill_Square(n-2)%MOD));
}


long long getAsym(int n){
    if(n <= 2)
        return 0;

    long long ret = 0;
    if(n%2 == 0) ret = dp[n] - (dp[n/2] + dp[(n-2)/2]);

    else ret = dp[n] - dp[(n-1)/2];

    return (ret + MOD)%MOD;



}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    ifstream inFile;
    inFile.open("../input");

    if(not inFile.bad()){
        int test_num = 0; inFile>>test_num;
        for(int cnt = 0; cnt < test_num; ++ cnt){
            int _length = 0; inFile>> _length;
            memset(dp, -1, 101*sizeof(long long));
            fill_Square(_length);
            cout<<getAsym(_length)<<endl;

        }



    }




    return 0;
}