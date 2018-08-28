#include <iostream>

#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <bitset>

using namespace std;


int T;
int N;
int M;


map<string, int> students;
vector<int> bitTable;



const int INF = 987654321;
int best = INF;


const int MAX_M = 21;
int aux[MAX_M];

bool simpleH(int sidx, int checkStudent){
    // [sidx, M) 까지 다 선택 했을 때 먹은 상태 , aux 배열에 저장
    // checkStudent | aux[sidx] 가 11111..11 l 이 되지 않으면 더이상 할 필요가 없다.
    return not (aux[sidx] | checkStudent)  == ((1<< N) - 1);

}



void solve(int fidx, int checkStudent, int pickNum){
    if(checkStudent == ((1<< N) - 1)){ // 종료
        best = min(best, pickNum);
        return;
    }
    // heuristic
    if(simpleH(fidx, checkStudent))return;

    if(fidx == M) return;

    int pickNext = (checkStudent | bitTable[fidx]);
    solve(fidx+1, pickNext, pickNum+1);
    solve(fidx+1, checkStudent, pickNum);
}




int pickFood;
void solve2(int checkStudent, int pickNum){
    if(checkStudent == ((1<< N) - 1)){ // 종료
        best = min(best, pickNum);
        return;
    }
    if(best <= pickNum) return;

    if(pickFood == ((1<< M) -1)){
        // 모든 음식을 골랐는데도 다 채울 수가 없는 경우이므로 pass 한다.
        return;
    }
    int noEatStudent = -1;
    for(int i = 0; i < N; ++i){
        if(checkStudent & (1<<i)) noEatStudent = i;
    }
    vector<int> eatlist;
    for(int fidx =0; fidx< bitTable.size(); ++fidx){
        if(pickFood & (1<<fidx)) continue;
        eatlist.emplace_back(fidx);
    }

    for(auto fidx : eatlist){
        // pick eatlist[fidx]
        int food = bitTable[fidx];
        // update pickFood
        pickFood += (1<<fidx);
        // update checkStudent
        // next
        solve2(checkStudent | food, pickNum+1);
        // rollback
        pickFood -= (1<<fidx);
    }












}


int main() {

    ifstream inFile;
    inFile.open("../input");

    inFile>>T;

    for(int test = 0; test < T; ++test){
        inFile >> N;
        inFile >> M;

        students.clear();
        bitTable.clear();
        memset(aux, 0, sizeof(int) * MAX_M);

        best = INF;
        pickFood = 0;
        for(int s = 0; s < N; ++s){
            string name; inFile >> name;
            students.insert(make_pair(name, s));
        }


        for(int f = 0 ; f < M; ++f){
            int foodInfo = 0;
            int tmp; inFile >> tmp;
            for(int i = 0; i < tmp; ++i){
                string name; inFile>>name;
                foodInfo += (1 << students[name]);
            }
            bitTable.emplace_back(foodInfo);
        }
        //###############################################################
//        solve(0, 0, 0);

//        for(int midx = 1; midx < M; ++midx){
//
//            aux[midx] = (aux[midx-1] | bitTable[midx]);
//
//        }
        solve2(0,0);
        cout<<best<<endl;



    }



    return 0;
}