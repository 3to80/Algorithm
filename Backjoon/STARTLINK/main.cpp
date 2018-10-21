#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>


using namespace std;

int N;

const int MAXN = 20;

int stateTable[MAXN][MAXN];
bool aux[MAXN];


int best = 987654321;


// N/2가 초기값으로 들어간다.

int getSum(bool flag){
    vector<int> tmp;
    for(int i = 0; i < N; ++i){
        if(aux[i] == flag)
            tmp.emplace_back(i);
    }
    int ret = 0;
    for(int i = 0 ; i < tmp.size(); ++i){
        // aux[i]에 대해
        for(int j = 0; j < tmp.size(); ++j){
            ret += stateTable[tmp[i]][tmp[j]];
        }
    }


    return ret;
}


void func(int n){
    //base case

    if(n == N/2){
        // aux에서 true인 거, false 인거 들에 대해 stateTable합을 구한다.
        int s1 = getSum(true);
        int s2 = getSum(false);
        best = min(best, abs(s1- s2));
        return;
    }
    // smallest는 제일 마지막 true의 옆에 것

    int smallest = -1;
    for(int i = N-1; i >= 0; --i){
        if(aux[i]){
            smallest = i;
            break;
        }
    }

    for(int pick = smallest +1; pick < N; ++pick){
        if(N- pick < N/2 - n ) continue;
        aux[pick] = true;
        func(n+1);
        aux[pick] = false;
    }
}
int main() {


    memset(stateTable, 0, sizeof(int) * MAXN * MAXN);
    memset(aux, 0, sizeof(bool) * MAXN);
    best = 987654321;

    cin >> N;
    for(int r = 0; r < N; ++r )for(int c= 0; c < N; ++c )
            cin >> stateTable[r][c];

    func(0);

    cout << best << endl;

    return 0;
}