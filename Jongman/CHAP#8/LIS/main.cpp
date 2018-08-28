#include <iostream>
// cpp 11에서 메르센 트위스터( 2^i  +=1 ) 를 이용한 난수 생성 헤더가 추가
#include <random>
#include <array>
#include <vector>


using namespace std;


int getRandomNumber(int min, int max){

    random_device rn;
    mt19937_64 rnd(rn());

    uniform_int_distribution<int> range(min, max);

    return range(rnd);

}


int MAX_LENGTH = 30;


void solve(int dp[], int target_idx, int arr[]){
    if(target_idx == MAX_LENGTH)
        return;

    int max_Value = 0;
    for(int i = 0; i < target_idx; ++i){
        if(arr[i] < arr[target_idx])
            max_Value = max(max_Value, dp[i]);
    }
    dp[target_idx] = max_Value+1;
    return solve(dp, target_idx+1, arr);
}



bool all_false(bool aval[]){
    for(int i = 0; i < MAX_LENGTH; ++i)
        if(aval[i])
            return false;
    return true;
}


void print(bool aval[]){
    cout<<endl<<"##### ";

    for(int i = 0; i < MAX_LENGTH; ++i)
        cout<<aval[i] << " ";
    cout<<endl;
}


int sole_exhaust2(const vector<int>& b){
    if(b.empty()) return 0;
    int maxValue = -1;
    for(int i = 0 ; i < b.size(); ++i){
        vector<int> rem ;
        for(int j = i+1; j < b.size(); ++j){
            if(b[j] > b[i])
                rem.push_back(b[j]);
        }
        maxValue = max(maxValue, sole_exhaust2(rem)+1);
    }
    return maxValue;
}


int solve_exhaust(int arr[], bool aval[]){
    /**
     * @param 시작점의 후보인 idx
     * @param source 배열
     * @param source에서 쓸 수 있는 것과 없는 것을 구분해줌
     * @return s_idx를 시작으로 할 때 가장 길이가 긴 lis의 길이
     */
//    print(aval);

    int s_idx = -1;
    for(int i = 0 ; i < MAX_LENGTH; ++i)
        if(aval[i]){
            s_idx = i;
            break;
        }

    if(s_idx == -1) return 0;
    aval[s_idx] = false;

//    print(aval);

    // 시작할 곳을 고름, 이게 참석하는거는, 고른것보다 더 큰 것을 생각하면 됨.


    int no_part = solve_exhaust(arr, aval);

    // 지워 나간다.
    for(int i = s_idx+1; i < MAX_LENGTH; ++i){
        if(arr[i] <= arr[s_idx] and aval[i])
            aval[i] = false;
    }

    int part = solve_exhaust(arr, aval) + 1;

    for(int i = s_idx+1; i < MAX_LENGTH; ++i){
        if(arr[i] <= arr[s_idx] and not aval[i])
            aval[i] = true;
    }

    aval[s_idx] = true;

    return max(no_part, part);

}



void update(bool arr[]){
    arr[0] = true;
}

int main() {

//    1. 시드 설정 : 하드웨어의 리소스를 랜덤하게 이용하는 특징, default는 mersen twister
//
//    2. 범위 설정 :
//
//    3. 난수 추출
//    난수 생성 형식과 타입 결정 : 분포도를 설정.



    int MIN = 0;
    int MAX = 30;
    int arr[MAX_LENGTH];
    fill_n(arr, MAX_LENGTH, 0);
//
//    array<int, 100> a;
//    a.fill(19);
//
//    for(auto tmp : a){
//        cout<<tmp << " " ;
//    }

    int dp[MAX_LENGTH];
    fill_n(dp, MAX_LENGTH, -1);
//    int array[100] = { [0 ... 99] = -1 }; 이렇게 배열 초기화를 할 수도 있다.

    bool aval[MAX_LENGTH];
    fill_n(aval, MAX_LENGTH, true);

    for(int i = 0; i < MAX_LENGTH; ++i){
        arr[i] = getRandomNumber(MIN, MAX);
        cout<<arr[i] << " ";
    }

    solve(dp, 0, arr);


    cout<<endl;
    int max_val = -1;
    for(int i = 0; i < MAX_LENGTH; ++i){
        cout<<dp[i] << " ";
        max_val = max(max_val, dp[i]);
    }

    cout<<endl<<max_val;

    cout<<endl<<solve_exhaust(arr, aval);

    vector<int> b;
    for(int i = 0 ; i < MAX_LENGTH; ++i)
        b.push_back(arr[i]);
    cout<<endl<<sole_exhaust2(b)<<endl;

    int test[10] = {0,1,2,3,4,5,6,7,8,9};
    cout<<test[-1]<<endl;
    cout<<test[-2]<<endl;
    cout<<test[-3]<<endl;
    cout<<test[-4];


    return 0;
}