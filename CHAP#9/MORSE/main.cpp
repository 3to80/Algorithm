#include <iostream>

using namespace std;


const int MAX_N = 101;
const int MAX_M = 101;

int n = 2;
int m = 2;



int DP[MAX_N][MAX_M];

int f(int n, int m){
    int &ret = DP[n][m];
    if(ret != 0) return ret;
    if(n ==0 or m == 0) return (ret = 1);
    return (ret = f(n-1, m) + f(n, m-1));
}


string g(int n, int m, int k){
    if(k == 0){
        // -를 n 개 o를 m 개
        string ret;
        for(int i = 0 ; i <n; ++i)
            ret += "-";
        for(int i = 0 ; i <m; ++i)
            ret += "o";

        return ret;
    }

    if( k < DP[n-1][m]) return "-" + g(n-1, m, k);
    else return "o" + g(n, m-1, k - DP[n-1][m]);


}



int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<f(2, 2);
    cout<<g(2,2,4);
    return 0;
}