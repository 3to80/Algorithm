#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>


const int MAX_ITM_NUM = 501;
int arr[MAX_ITM_NUM];
int TEST_NUM;
int NUM ; //END 지점
int K;
int cacheLENGH[MAX_ITM_NUM+1];
int cacheCNT[MAX_ITM_NUM+1];


using namespace std;






int get_maxLength(int sidx){
    int &ret = cacheLENGH[sidx+1];

    if(ret != -1) return ret;

    ret = 1;
    for(int nidx = sidx+1; nidx < NUM; ++nidx){
        if(sidx == -1 or arr[nidx] > arr[sidx])
           ret = max(get_maxLength(nidx)+1, ret);
    }
    return ret;
}



int get_maxLength_CNT(int sidx){
    int &ret = cacheCNT[sidx+1];

    if(get_maxLength(sidx) == 1) return (ret = 1);

    if(ret != -1) return ret;
    ret = 0;
    for(int nidx = sidx+1; nidx < NUM; ++nidx){
        if(sidx == -1 or arr[nidx] > arr[sidx]
           and get_maxLength(sidx) == get_maxLength(nidx)+1){
            ret += get_maxLength_CNT(nidx);

        }
    }
    return ret;
}


void getKth(int sidx, int k, vector<int> &ans){
    // 시작값 찾기.
    if(sidx != -1) ans.emplace_back(arr[sidx]);

    map<int, int> followers;
    for(int nidx= sidx+1; nidx< NUM; ++nidx){
        if(sidx == -1 or arr[sidx] < arr[nidx]
           and get_maxLength(sidx) == get_maxLength(nidx)+1){
            followers.insert(pair<int, int>(arr[nidx], nidx));
        }
    }

    for(auto itm : followers){
        int idx = itm.second;
        int cnt = get_maxLength_CNT(idx);
        if(cnt <= k ) k -= cnt;
        else{
            getKth(idx, k, ans);
            break;
        }


    }







}



//int count(int sidx){
//    int ret = 1;
//
//    for(int nidx = sidx+1; nidx < NUM; ++nidx){
////        if(arr[nidx])
//
//
//    }
//
//
//
//}




int main() {
    std::cout << "Hello, World!" << std::endl;

    ifstream inFile;
    inFile.open("../input");
    inFile >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        inFile >> NUM >> K;
        memset(arr, 0, sizeof(int) * MAX_ITM_NUM);
        memset(cacheLENGH, -1, sizeof(int) * MAX_ITM_NUM);
        memset(cacheCNT, -1, sizeof(int) * MAX_ITM_NUM);


        for(int i = 0; i < NUM; ++i) inFile>> arr[i];


        int level = get_maxLength(-1);
        cout<<level-1<<endl;
        get_maxLength_CNT(-1);

//        for(int i = 0 ; i <NUM+1; ++i)
//            cout<< cacheLENGH[i] << " ";
//        cout<<endl;
//
//        for(int i = 0 ; i <NUM+1; ++i)
//            cout<< cacheCNT[i] << " ";
//        cout<<endl;

        vector<int> ans;
        getKth(-1, K-1, ans);
        for(auto itm : ans){
            cout << itm<< " " ;
        }
        cout<<endl;

    }



    return 0;
}