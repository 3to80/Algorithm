#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int T;



int N;

const int BIGNUM = 987654321;
const int MAX= 10001;
int M[MAX];
int E[MAX];



int main() {


    ifstream inFile;
    inFile.open("../input");


    inFile >> T;
    for(int test_case = 0 ; test_case < T; ++test_case){
        inFile >> N;
        memset(M, 0, sizeof(int) * MAX);
        memset(E, 0, sizeof(int) * MAX);

        for(int i = 0 ; i < N; ++i)
            inFile >> M[i];
        for(int i = 0 ; i < N; ++i)
            inFile >> E[i];

        vector<pair<int, int>> time;
        for(int i = 0; i < N; ++i)
            time.emplace_back(make_pair(E[i], M[i]));

        sort(time.begin(), time.end());

        int ans = 0;


        int m_time = 0;



        for(auto iter = time.crbegin(); iter != time.crend(); ++iter){

            int pick = iter->first;
            m_time += iter->second;
            ans = max(ans, pick + m_time);
        }

        cout << ans << endl;






    }


    return 0;
}