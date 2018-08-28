#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <math.h>

using namespace std;


int OCCUR;
int SRC_NUM;
map<string, int> dict;
vector<string> wordlist;
double *initProb; // occur 개
double **T; // occur by occur
double **M; // occur by occur
vector< vector<string> > srcList; // 처리해야할 문장수, SRC_NUM개가 주어진다.


void print(const vector<string>& data){
    for(const auto &str : data)
        cout<< str << " ";
    cout << endl;
}
void print(const vector< vector<string> >& data){
    for(const auto &strList : data)
        print(strList);
}
void print(double *data){
    for(int r = 0 ; r < OCCUR; ++r)
        cout<<data[r]<< " ";
    cout<< endl;

}
void print(double **data){
    for(int r = 0 ; r < OCCUR; ++r)
        print(data[r]);
}



const int MAX_WORDSET_SIZE = 501;
const int N = 101;

double DP[MAX_WORDSET_SIZE][N];
int choice[MAX_WORDSET_SIZE][N];


double solve_iter(const vector<string> &R,  int prev_q_word_idx, int curr_pos);
string solve(const vector<string> &R, vector<string> &ans);
string reconstruct(int a, int b, int limit);

int main() {


    ifstream inFile;
    inFile.open("../input");
    if(inFile.bad()){
        cout<< "FILE OPEN ERROR";
        return -1;
    }
    inFile>> OCCUR;
    inFile >> SRC_NUM;

    // 여기 선언부 함수로 해서 간략하게 표현하기
    for(int i = 0 ; i< OCCUR; ++i){
        string tmp; inFile>>tmp;
        dict.insert(pair<string, int>(tmp, i));

        wordlist.emplace_back(tmp);
    }

    initProb = new double[OCCUR];
    for(int i = 0 ; i< OCCUR; ++i) inFile>>initProb[i];


    T = new double*[OCCUR];
    for(int i = 0 ; i< OCCUR; ++i)T[i] = new double[OCCUR];

    for(int r = 0; r < OCCUR; ++r)
        for(int c = 0; c < OCCUR; ++c)
            inFile >> T[r][c];

    M = new double*[OCCUR];
    for(int i = 0 ; i< OCCUR; ++i)M[i] = new double[OCCUR];
    for(int r = 0; r < OCCUR; ++r)
        for(int c = 0; c < OCCUR; ++c)
            inFile >> M[r][c];



    for(int i = 0; i < SRC_NUM; ++i){
        int num = 0; inFile>>num;
        srcList.emplace_back(vector<string>());
        for(int j = 0; j < num; j++){
            string tmp; inFile>>tmp;
            srcList[i].push_back(tmp);
        }
    }

    print(wordlist);
    print(initProb);
    print(T);
    print(M);
    print(srcList);

    //###################################################3


    for(int i = 0; i < SRC_NUM; ++i){
////        srcList[i];
        memset(DP, 0, sizeof(double) * MAX_WORDSET_SIZE * N);
        vector<string> ans;
        cout<<solve(srcList[i], ans);
        print(ans);
//
    }




    //###################################################3
    for(int i = 0 ; i< OCCUR; ++i)delete[] M[i];delete []M;
    for(int i = 0 ; i< OCCUR; ++i)delete[] T[i];delete []T;
    delete []initProb;




    return 0;
}

double solve_iter(const vector<string> &R, int prev_q_word_idx, int curr_pos){
    double &ret = DP[prev_q_word_idx][curr_pos];

    if(ret != 0) return ret;

    if(curr_pos == R.size())
        return (ret = 1);
    double maxValue = 0;
    int picked_pos = -1;

    for(int idx = 0; idx < wordlist.size(); ++idx){

        double next_step = T[prev_q_word_idx][idx] * M[idx][dict[R[curr_pos]]] * solve_iter(R, idx, curr_pos+1);
        if(maxValue < next_step){
            maxValue = next_step;
            picked_pos = idx;
            choice[prev_q_word_idx][curr_pos] = picked_pos;


        }

    }
    return (ret = maxValue);


}
string solve(const vector<string> &R, vector<string> &ans){

    double maxValue = 0;


    int curr_pos = 0;
    int picked_pos = -1;
    for(int idx = 0; idx < wordlist.size(); ++idx){
        // wordlist[idx]가 제일 처음에 올 확률 * 그게 왔을 때 R로 분류할 확률
        double next_step = initProb[idx] * M[idx][dict[R[curr_pos]]] * solve_iter(R, idx, curr_pos+1);

        if(maxValue < next_step){
            maxValue = next_step;
            picked_pos = idx;

            choice[0][curr_pos] = picked_pos;
        }

    }
    return reconstruct(picked_pos, 0, R.size()+1);

//    return maxValue;
}


string reconstruct(int prev, int curr, int n){
    int choose = choice[prev][curr];
    string ret = wordlist[prev];
    if(curr < n-1)
        ret = ret + " " + reconstruct(choose, curr+1, n);
    return ret;

}