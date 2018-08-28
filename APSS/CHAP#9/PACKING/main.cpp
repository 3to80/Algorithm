#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;



int max_test_num;

const int MAX_OBJ_CNT= 101;
const int MAX_CAP = 1001;



template <typename T>
void print(T* arr, int length){
    for(int i = 0 ; i < length; ++i)
        cout << arr[i] << " ";
    cout << endl;
}




const int *WEIGHT;
const int *HAPPINESS;
const string *NAME;
int NUM;



int dp[MAX_CAP][MAX_OBJ_CNT];
int pickedItm[MAX_CAP][MAX_OBJ_CNT];





int solve(int w, int start){
    if(start == NUM) return 0;

    int &ret = dp[w][start];
    if(ret != -1) return ret;

    ret = solve(w, start + 1);
    if(w >= WEIGHT[start])
        ret= max(ret, HAPPINESS[start] + solve(w-WEIGHT[start], start+1));

    return ret;

}

void reconstruct(int cap, int itm, vector<string> & picked){

    if(itm == NUM) return;
    if(solve(cap, itm) == solve(cap, itm+1))
        return reconstruct(cap, itm+1, picked);
    picked.push_back(NAME[itm]);
    return reconstruct(cap-WEIGHT[itm], itm+1, picked);


}




void getMaxPath(int w, int start, vector<int>& ret){
    int current= pickedItm[w][start];
    if(current != -1){
        ret.emplace_back(current);
        getMaxPath(w - WEIGHT[current], current+1, ret);

    }

}



int main() {

    ifstream inFile;
    inFile.open("../input");
    if(inFile.bad())cout<<"file open error";

    inFile>> max_test_num;

    for(int test_case = 0; test_case < max_test_num; ++test_case){
        int obj_cnt; inFile>>obj_cnt; NUM = obj_cnt;
        int cap; inFile >> cap;


        auto obj_name = new string[obj_cnt];
        auto obj_weight = new int[obj_cnt];
        auto obj_happiness = new int[obj_cnt];
        auto flagTable = new bool[obj_cnt];


        memset(dp, -1, sizeof(int) * MAX_CAP * MAX_OBJ_CNT );

        memset(pickedItm, -1, sizeof(int) * MAX_CAP * MAX_OBJ_CNT );


        for(int i = 0; i < obj_cnt; ++i){
            inFile>> obj_name[i];
            inFile>> obj_weight[i];
            inFile>> obj_happiness[i];
        }




//        print<string>(obj_name, obj_cnt);
//        print<int>(obj_weight, obj_cnt);
//        print<int>(obj_happiness, obj_cnt);

        //################################
        WEIGHT = obj_weight;
        HAPPINESS = obj_happiness;
        NAME = obj_name;


        cout << solve(cap, 0) << " ";
////        print<int>(pickedItm, MAX_CAP);
        vector<string> path;
        reconstruct(cap, 0, path);
        cout<<path.size()<<endl;
        for(auto i : path)
            cout<<i<<endl;






        //################################
        delete []obj_name;
        delete []obj_weight;
        delete []obj_happiness;
        delete []flagTable;


    }





    return 0;
}