#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int N;
const int MAX_N = 12;

int OPS[4];

vector<int> nums;



int solve(int idx){
    // [0, idx) ㄲ지 연산한거
    if(idx == 0)
        return nums[0];

    int maxValue = -1;


    for(int i = 0; i < 4; ++i){
        if(OPS[i] > 0){
            OPS[i]--;
            switch(i){
                case 0:
                    maxValue = max(maxValue, solve(idx-1) + nums[idx] );
                    break;
                case 1:
                    maxValue = max(maxValue, solve(idx-1) - nums[idx] );
                    break;
                case 2:
                    maxValue = max(maxValue, solve(idx-1) * nums[idx] );
                    break;
                case 3:
                    maxValue = max(maxValue, solve(idx-1) / nums[idx]);
                    break;
            }

            OPS[i]++;
        }
    }
    return maxValue;


}

int solve2(int idx){
    // [0, idx) ㄲ지 연산한거
    if(idx == 0)
        return nums[0];

    int minValue= 987654321;


    for(int i = 0; i < 4; ++i){
        if(OPS[i] > 0){
            OPS[i]--;
            switch(i){
                case 0:
                    minValue = min(minValue, solve2(idx-1) + nums[idx] );
                    break;
                case 1:
                    minValue = min(minValue, solve2(idx-1) - nums[idx] );
                    break;
                case 2:
                    minValue = min(minValue, solve2(idx-1) * nums[idx] );
                    break;
                case 3:
                    minValue = min(minValue, solve2(idx-1) / nums[idx]);
                    break;
            }

            OPS[i]++;
        }
    }
    return minValue;


}

int main() {


    ifstream inFile ;
    inFile.open("../input");

    inFile>>N;

    for(int i = 0; i < N; ++i){
        int tmp; inFile >> tmp;
        nums.emplace_back(tmp);
    }
    for(int i = 0; i < 4; ++i){
        int tmp; inFile >> tmp;
        OPS[i] = tmp;

    }




    // i번째 선택된 연산자는

    cout << solve(N-1)<<endl;
    cout << solve2(N-1)<<endl;






    return 0;
}