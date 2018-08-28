#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;



const int MAX_VAL = 987654321;

vector<int> subSum;
vector<int> subSquare;
int minSquare(const vector<int>& arr, int start, int end){


//    int mean = subSum[end-1]/(end-1 - start);
//    return subSquare[end-1] - subSquare[start] - 2*mean *(subSum[end-1] - subSum[start])
//    + mean * mean * (end-start);
//
    /**
     * @brief: [start, end) 까지의  평균값을 구한다.
     * @attention: [start, end)
     */
    // arr에서 num 만큼 가장 작은 숫자를 고른다.
    int sum= 0;
    for(int i = start; i < end; ++i)
        sum += arr[i];

    int mean = (int)round(sum/(end-start));


    int ms = 0;
    for(int i = start; i < end; ++i)
        ms += pow(arr[i] - mean, 2);

    return ms;

}

int dp[11][101];
int quantize(int set_num, const vector<int> &rem, int start){
    /**
     * @attention: rem은 오름차순 정렬되어 들어와야 됨.
     *              [start, end) 상태. end는 항상 rem.size()가 된다.
     *              set_num은 항상 arr 사이즈보다 크다고 가정한다.
     * @brief: main recursion
     * @invaraint
     */

    if(dp[set_num][start] != -1) return dp[set_num][start];

    if(set_num == 1) return minSquare(rem, start, (int)rem.size());

    int minValue = MAX_VAL;
    for(int i = 1; i <= rem.size()-(set_num-1)-start; ++i){
        // 정렬된 rem에 대해 i개 만큼 가져가진다.
        int tmp =  minSquare(rem, start, start + i) + quantize(set_num-1, rem, start + i );
        minValue = min(minValue, tmp);
    }
    dp[set_num][start] = minValue;
//    cout<<endl<<minValue<< " " << dp[set_num][start] <<endl;
    return minValue;
}


void print(const vector<int> &arr){
    for(auto i : arr){
        cout << i<< " ";
    }
    cout<<endl;
}
int main() {
    ifstream inFile;
    inFile.open("../input");
    int loop_num;
    inFile >> loop_num;
    for(int cnt = 0; cnt < loop_num; ++cnt){
        for(int i = 0 ; i < 11; ++i)
            fill_n(dp[i], 101,  -1);

        int arr_num = 0; inFile>>arr_num;
        int set_num = 0; inFile >> set_num;
        vector<int> arr;
        for(int i = 0; i < arr_num; ++i){
            int tmp;
            inFile>>tmp;
            arr.emplace_back(tmp);
        }
        sort(arr.begin(), arr.end());
        subSum.push_back(0);
        subSquare.push_back(0);

        for(int i = 0 ; i < arr.size();++i){
            subSum.push_back(subSum[i]+arr[i]);
            subSquare.push_back(subSquare[i]+arr[i] * arr[i]);
        }



        cout<<quantize(set_num, arr, 0)<<endl;
//        cout<<minSquare(arr, 0, arr.size())<<endl;

//        for(int r = 0; r  <11; ++r){
//            for(int c = 0; c  <101; ++c){
//                cout<<dp[r][c] <<  " ";
//            }
//        }
//        subSum.clear();
//        subSquare.clear();

    }

    return 0;
}