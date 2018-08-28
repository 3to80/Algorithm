#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

long long N;
long long M;
vector<long long> value;
vector<long long> cost;

const int MAXC = 201;
long long CACHE[MAXC];



int main() {


    ifstream inFile;
    inFile.open("../input");


    int T; inFile>> T;
    for(int t= 0 ; t < T; ++t){
        // 사용되는 자료구조 초기화 유념
        inFile>> N; inFile >> M; M/=100;
        cost.clear();
        value.clear();


        for(int n = 0; n < N;++n){
            // 내가 하는 실수의 대부분은 update 되는 자료구조 초기화 혹은 엉뚱한 값 업데이트 같은 것들
            // SEGMENTATION ERROR는 할당되지 않은 메모리에 접근하려고 할 때 발생하는 거임.
            long long tmp;inFile>>tmp;
            cost.emplace_back(tmp/100);
            inFile >> tmp;
            value.emplace_back(tmp);

        }
        memset(CACHE, 0, MAXC * sizeof(int));
//####

        for(int c =0; c < M+1; ++c){
            long long maxV = 0;
            for(int idx = 0; idx < cost.size(); ++idx){
                if(c - cost[idx] >= 0)
                    maxV = max(maxV, CACHE[(c - cost[idx])%MAXC] + value[idx]);
            }
            CACHE[c%MAXC] = maxV;
        }


        cout<< CACHE[M%MAXC] << endl;


    }



    return 0;
}