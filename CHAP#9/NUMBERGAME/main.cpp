#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int N; // board NUM;
const int MAX_N = 51; // 최대 보드 길이
const int MAX_VAL = 1001;
const int MIN_VAL = -987654321;

vector<int> board;

template <typename T>
void print(vector<T> vec){
    for(auto itm : vec){
        cout<< itm << " " ;
    }

    cout <<endl;

}


// 이상태로 cache을 할 수 있나 ? 이러면 diff의 최대값인 25000 정도도 같이 잡아야 될 거 같은데 거기에 diff의 절대값으로 만들어서 cache를 한다고 하자 diff의 부호 까지 신경을 써야 된느 거가인ㄴ가
// 그럼 50 50 25000 2 6250만 64mb 간신히 넘긴 할겟따






int cache[50][50];

int canWin(int left, int right){
    int &ret = cache[left][right];
    if(ret != MIN_VAL){
        return ret;
    }

    if(left > right){
        // 현재 스테이트에서 더 뽑을 수 있는게 없다.
        // canWin이
        // point를 2개 다 놔뒀다고 해보자. 그럼 현재 state가 누군지 까지 함께 기억을 해야 한다.
        // 반대로 현재 diff 값이 -라 하자. 이건 상대적인 diff, 즉 내가 누군지 상관없이 diff가 -이면 나의 패배 라는 것을 의미
        // diff >0 이면, 즉 내가 상대방보다 diff만큼 더 가졌다는 것을 의미

        return 0;

    }

    // 다음의 결과가 모든 false면 나는 무조건 지는거, 즉 and로 가면 된다.


    ret = MIN_VAL;
    ret = max(ret, -canWin(left+1, right)+board[left]);
    ret = max(ret, -canWin(left, right-1)+board[right]);

    if(right - left +1 >=2 ){
        ret = max(ret, -canWin(left+2, right));
        ret = max(ret, -canWin(left, right-2));
    }


    return ret;
}


int main() {
    ifstream inFile;
    inFile.open("../input");
    int test_case; inFile >> test_case;

    for(int t = 0; t < test_case; ++t){
        board.clear();
        inFile >> N;
        for(int n = 0; n < N; ++n){
            int tmp; inFile >> tmp;
            board.emplace_back(tmp);
        }

        for(int r = 0; r < 50 ; ++r){
            for(int c = 0; c < 50 ; ++c){

                cache[r][c] = MIN_VAL;
            }

        }

        cout << canWin(0, board.size()-1) << endl;




    }



    return 0;
}