#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <assert.h>
#include <typeinfo>

using namespace std;
int T;
string EGG;


vector<int> TARGET; // Target[0]은 1자리 숫자
int M;

// TARGET보다 더 사전상 앞에 있고 m 의 배수인 것들의 개수를 구한다.


const long long MOD = 1000000007;
const int MAX_TABLE = 65535;
const int MAX_M = 21;
int cache[MAX_TABLE][MAX_M];

int conversion(const vector<bool> &boolTable){

    int ret = 0;
    for(int i = 0; i< boolTable.size(); ++i){
        int val = (boolTable[i])?1:0;
        ret += val * pow(2, i);
    }
    return ret;

}
int solve_type2(vector<bool> &boolTable, int level, int target){


    if(level == -1){
        if(target == 0) return 1;
        else return 0;
    }

    int ret = 0;
    int no_dup[10];
    memset(no_dup, 0, sizeof(int) * 10);

    for(int idx = 0; idx < TARGET.size(); ++idx){
        if(boolTable[idx] and no_dup[TARGET[idx]] == 0){
            no_dup[TARGET[idx]]++;

            boolTable[idx] = false;
            int tmp = (TARGET[idx]%M) * (int)pow(10, level) % M;
            ret += solve_type2(boolTable, level-1, (target + tmp)%M)%MOD;
            boolTable[idx] = true;
        }
    }


    return ret;


}
int solve(vector<bool> &boolTable, int level, int target){

    if(level == 0) return 0;

    int no_dup[10];
    memset(no_dup, 0, sizeof(int) * 10);
    int ret = 0;
    for(int idx = 0; idx < TARGET.size(); ++idx){
        if(TARGET[idx] > TARGET[level]) continue;
        if(boolTable[idx] and no_dup[TARGET[idx]] == 0){
            no_dup[TARGET[idx]]++;
            boolTable[idx] = false;
            int tmp = (TARGET[idx]%M) * (int)pow(10, level) % M;
            if(TARGET[idx] == TARGET[level]) ret += (solve(boolTable, level-1, (target + tmp)%M))%MOD;
            else ret += solve_type2(boolTable, level-1, (target + tmp)%M) %MOD;
            boolTable[idx] = true;
        }
    }

    return ret;

}




int use_more(const vector<bool> &boolTable){
    // 더 쓸 수 있는게 있는가
    int ret = 0;
    for(auto itm : boolTable){
        if(itm) ++ret;
    }
    return ret;
}


int solve_simple(vector<bool> &boolTable, int val){

    int &ret = cache[conversion(boolTable)][val];
    if(ret != -1) return ret;

    int cand = use_more(boolTable);

    if(cand == 0){
        if(val == 0) return (ret = 1);
        else return (ret = 0);
    }
    ret = 0;

    int level = cand-1;




    int no_dup[10];
    memset(no_dup, 0, sizeof(int) * 10);

    for(int idx = 0; idx < TARGET.size(); ++idx){
        if(boolTable[idx] and no_dup[TARGET[idx]] == 0){
            no_dup[TARGET[idx]]++;
            // 현재 level 자리에 채워져야 한다. 자기보다 앞에 작은 것이 하나라도 있으면.. 근데
            boolTable[idx] = false;
            int tmp = ((int)pow(10,level) % M)  * (TARGET[idx]%M);
            int new_val = val;
            new_val += tmp; new_val  %= M;
            ret += solve_simple(boolTable, new_val );
            boolTable[idx] = true;
        }
    }



    return ret;
}


int solve(vector<bool> &boolTable, int val){
//    cout << "solve 들어 갈 뗴 " << val << endl;
    int ret = 0;
    int cand = use_more(boolTable);
    if(cand == 1) return 0; // 원본과 같기 때문에 return 0
    int level = cand -1;

    // 0 - 9  중복을 제거하기 위해서
    int no_dup[10];
    memset(no_dup, 0, sizeof(int) * 10);

    for(int idx = 0; idx < TARGET.size(); ++idx){

        if (TARGET[idx] > TARGET[level]) continue;

        if (boolTable[idx] and no_dup[TARGET[idx]] == 0) {
            no_dup[TARGET[idx]]++;
            boolTable[idx] = false;


            int tmp = (TARGET[idx] % M) * ((int) pow(10, level) % M);
            int new_val = val;
            new_val += tmp; new_val  %= M;
            if (TARGET[idx] == TARGET[level]) ret += solve(boolTable, new_val);
            else ret += solve_simple(boolTable, new_val);
            boolTable[idx] = true;
        }

    }
    return ret;
}






// 제일 처음 들어가는건 solve(0, 0, TARGET.size(), false)
int solve(int visited, long long tracing, int rem, bool flag){


    if(rem == 0){
        if(flag == false) return 0;
        if(tracing%M == 0){
//            cout << " 들어온 경우 " << rem << " " << tracing << " " << flag << endl ;
            return 1;
        }
        else return 0;
    }


//    if(visited == (1 << TARGET.size()) -1){
//        if(tracing%M == 0){
//            return 1;
//        }
//        else return 0;
//    }

    int ret = 0;
    int level = rem-1;

    bool dup[10]; // true가 되면 이전에 쓰인거를 의미
    memset(dup, false, 10 * sizeof(bool));
    for(int idx = 0; idx < TARGET.size(); ++idx){
        if( visited & (1 << idx) or dup[TARGET[idx]] ) continue;
        if( not flag and TARGET[idx] > TARGET[level]) continue;

        int target = TARGET[idx];
        dup[target] = true;
        int new_visit = visited | (1 << idx);
        // pow(10, level) 여기 자체부터 overflow된 값이 나와 버려서, 계속 이상한 결과가 나왔다. 만약 %M으로 처리를 하려고 했으면 pow(10, level)을 내가 직접 만들어서
        // %M을 10 곱할 떄마다 계속 해줘야 됬었음.
        long long  next_tracing = (long long )pow(10, level);
        next_tracing *= (TARGET[idx]);
//        next_tracing %= M;
        next_tracing += tracing;
//        next_tracing %= M;

        if(not flag and TARGET[idx] == TARGET[level]){
            // 자기 자신이 들어오는 경우
            ret += solve(new_visit, next_tracing, rem-1, false);
        }
        else{
            ret += solve(new_visit, next_tracing, rem-1, true);
        }

    }


    return ret;
}










vector<int> to_vectorInt(const string& s){
    vector<int> ret;


    // stack overflow에서 cpp 에서 string을 vector<int>로 바꾸는거 찾아보기
    for(int i = s.size()-1; i  > -1; --i){
        char tmp = s[i];
        ret.emplace_back(atoi(&tmp));
    }

    return ret;

}


int main() {
//    std::cout << "Hello, World!" << std::endl;
    ifstream inFile;
    inFile.open("../input");
    inFile >> T;
    for(int test_case = 0; test_case < T; ++test_case){
        inFile >> EGG; inFile >> M;
        vector<int> src = to_vectorInt(EGG);
        TARGET = src;
        vector<bool> boolTable;
        memset(cache, -1, sizeof(int) * MAX_TABLE * MAX_M);

        for(int i = 0 ; i < src.size() ; ++ i) boolTable.emplace_back(true);
//        cout << solve(boolTable, src.size()-1, 0) << endl;
//        cout<< solve(boolTable, 0)<<endl;
        cout<< solve(0, 0, TARGET.size(), false) <<endl;

    }

    int a = 0;
//    assert( 0 );
    return 0;
}
