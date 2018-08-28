#include <iostream>
#include <random>
#include <vector>

using namespace std;





void print(const vector<int> &src){
    for(auto i : src){
        cout<<i << " " ;
    }
    cout<<endl;
}

vector<int> getRandomArray(int minV, int maxV, int num){
    // [minV, maxV] 사이의 random 변수를 추출


    vector<int> ret;
    random_device rn;

    for(int i = 0 ; i < num ; ++i){
        mt19937_64 rnd(rn());
        uniform_int_distribution<int> range(minV, maxV);
        ret.emplace_back(range(rnd));
    }
    return ret;

}


vector<int> getRandomArray_no_dup(int minV, int maxV, int num){
    // [minV, maxV] 사이의 수를 dup 없이 num개 추출
    vector<int> ret;
    random_device rn;
    int arr[num] = {0};
    fill_n(arr, num, 0);

    for(int i = 0 ; i < num ; ++i){
        mt19937_64 rnd(rn());
        uniform_int_distribution<int> range(minV, maxV);
        ret.emplace_back(range(rnd));
    }
    return ret;
}

const int Num_A = 1;
const int Num_B = 1;
int DP[Num_A][Num_B];

vector<int> A;
vector<int> B;


int max_JLIS(const vector<int> &A, const vector<int> &B){

    if(A.empty() and B.empty())
        return 0;

    int maxValue = -1;
    for(int i = 0 ; i < A.size(); ++i){
        vector<int> remA;
        vector<int> remB;
        for(int j = i +1; j < A.size(); ++j)
            if(A[j] > A[i])
                remA.push_back(A[j]);
        for(int k = 0; k < B.size(); ++k)
            if(B[k] > A[i])
                remB.push_back(B[k]);
        maxValue = max(maxValue, max_JLIS(remA, remB) + 1);
    }
    for(int i = 0 ; i < B.size(); ++i){
        vector<int> remA;
        vector<int> remB;
        for(int j = i +1; j < B.size(); ++j)
            if(B[j] > B[i])
                remB.push_back(B[j]);
        for(int k = 0; k < A.size(); ++k)
            if(A[k] > B[i])
                remA.push_back(A[k]);
        maxValue = max(maxValue, max_JLIS(remA, remB) + 1);
    }

    return maxValue;
}

int max_JLIS_DP(int idx_a, int idx_b){


    if(DP[idx_a][idx_b] != -1)
        return DP[idx_a][idx_b];


    int maxValue = 2;
    int standard = max(A[idx_a], B[idx_b]);

    for(int i = idx_a +1; i < A.size(); ++i){
        if(A[i] > standard)
            maxValue = max(maxValue, max_JLIS_DP(i, idx_b)+1);
    }


    for(int i = idx_b +1; i < B.size(); ++i){
        if(B[i] > standard)
            maxValue = max(maxValue, max_JLIS_DP(idx_a, i)+1);
    }

    DP[idx_a][idx_b] = maxValue;
    return maxValue;

}


int main() {
    std::cout << "Hello, World!" << std::endl;



    A = getRandomArray(2, 30, Num_A);
    B = getRandomArray(6, 30, Num_B);

    A[0] = 2;
    B[0] = 1;
    for(int i = 0 ; i < Num_A; ++i)
        fill_n(DP[i], Num_B, -1);


    print(A);
    print(B);


    cout<< max_JLIS(A,B)<<endl;
    int maxValue = -1;
    for(int i = 0 ; i < Num_A; ++i){
        for(int j = 0 ; j < Num_B; ++j){
            maxValue = max(maxValue, max_JLIS_DP(i,j));
            cout<< max_JLIS_DP(i,j)<<" ";
        }
    }
    cout<<endl<<maxValue;
//    cout<< max_JLIS_DP(0,0);
    return 0;
}