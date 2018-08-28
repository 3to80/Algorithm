#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>


using namespace std;


int T;
int N;
const int MAX_N = 21;
int M;
const int MAX_M = 21;


map<string, int> friends;
bool foodTable[MAX_M][MAX_N]; // 어떤 음식에 대해 (row)  특정학생(col)이 먹을 수 있으면 true, 아니면 false
bool checkTable[MAX_N]; // 학생들이 뭘 먹을 수 있고 먹을 수 없는지를 나타냄
bool pickedFoodTable[MAX_M]; // 처음엔 false, 음식을 추가할 때마다 true가 된다.


bool isAllTrueCheck(){
    // chckTable이 모두 True인지 본다.
    for(int i = 0; i < N; ++i)
        if(not checkTable[i]) return false;

    return true;
}


int getIntersectNum(int foodIdx){

    int ret = 0;
    for(int i = 0 ; i < N ; ++i)
        if(foodTable[foodIdx][i] and !checkTable[i] )++ret;

    return ret;

}

void updateCheckTable(int pickedFoodIdx){
    for(int i = 0 ; i < N ; ++i)
        if(foodTable[pickedFoodIdx][i])
            checkTable[i] = true;

}
void rollBackTable(int pickedFoodIdx){
    for(int i = 0 ; i < N ; ++i)
        if(foodTable[pickedFoodIdx][i])
            checkTable[i] = true;

}

int solve(){
    if(isAllTrueCheck()) return 0;
    vector< pair<int , int> > temp;
    for(int i = 0; i < M; ++ i){
        if(not pickedFoodTable[i]){// 선택되지 않은 food 들에 대해,
            // 이 음식 만든는 것을 선택한다면, 몇 명의 학생을 추가적으로 먹일 수 있는지를 알아본다.
            int cnt = getIntersectNum(i); // 추가적으로 먹일 수 있는 학생의 수
            temp.emplace_back(make_pair(cnt, i));

        }
    }
    sort(temp.begin(), temp.end());

    //가장 많이 먹일 수 있는 음식 번호
    int pickedFoodIdx = temp.back().second;
    pickedFoodTable[pickedFoodIdx] = true;
    updateCheckTable(pickedFoodIdx);

    return 1+ solve();

}



int best = 987654321;
//void ans = solveExhaustiveSearch(0, 0)
void solveExhaustiveSearch(int start, int pickNum){

    if(isAllTrueCheck()){
        best = min(best, pickNum);
        return;
    }
    if(start == M){
        cout<< " 다 써도 못 채움 "<< endl;
        best= -1;
        return;
    }


    int pickFoodIdx = start;

    bool prev[N];
    for(int i = 0; i < N; ++i) prev[i] = checkTable[i];

    updateCheckTable(pickFoodIdx);
    solveExhaustiveSearch(start+1, pickNum+1);

    //rollback
    for(int i = 0; i < N; ++i) checkTable[i] = prev[i];

    solveExhaustiveSearch(start+1, pickNum);




}



int main() {
    ifstream inFile;
    inFile.open("../input");
    inFile >> T;

    for(int test_case = 0; test_case < T; ++test_case){
        best = 987654321;
        friends.clear();
        memset(foodTable, false, sizeof(bool) * MAX_M * MAX_N);
        for(int i = 0; i < MAX_M; ++i){
            for(int j = 0; j < MAX_N; ++j)
                foodTable[i][j]= 0;
        }

        memset(checkTable, false, sizeof(bool) * MAX_N);

        memset(pickedFoodTable, false, sizeof(bool) * MAX_M);

        inFile >> N;inFile >> M;
        for(auto i = 0; i < N; ++i){
            string tmp; inFile>>tmp;
            friends.insert(make_pair(tmp, i));
        }

        for(auto i = 0; i < M; ++i){
            int t_num; inFile>> t_num;
            vector<string> tmp;
            for(auto j = 0; j < t_num; ++j){
                string t_tmp; inFile>>t_tmp;
                int friend_idx = friends[t_tmp];
                foodTable[i][friend_idx] = true;
            }
        }


        // ******************input 검증 완료

        solveExhaustiveSearch(0,0);
        cout<<best << endl;
//        int ans = solve();
//        cout<<ans << endl;

    }
    return 0;
}