#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <bitset>

using namespace std;


int T;
int N;
const int MAX_N = 21;
int color[MAX_N][MAX_N];
// 각 흰칸에 쓴 숫자, 아직 아무것도 안썼으면 0
int value[MAX_N][MAX_N];

// 각 칸에 해당하는 두 힌트의 번호
int hint[MAX_N][MAX_N][2];


int Q;

// SUM :힌트 칸에 쓰인 숫자 , length : 힌트 칸에 해당하는 흰 칸의 수 , known : 힌트 칸에 해당하는 흰칸에 쓰인 숫자들의 집합
int sum[MAX_N * MAX_N ], length[MAX_N * MAX_N ], known[MAX_N * MAX_N];





void printSolution(){

    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c)
            cout << value[r][c];
        cout<<endl;
    }

}



int getSum(int bitmask){
    int ret = 0;
    for(int i = 0 ; i < 9; ++i){
        if(bitmask & (1<<i)){
            ret += (i +1);
        }
    }
    return ret;
}

int getNum(int bitmask){

    // [0 ~ 9] 자리 까지 1의 개수를 센다.
    int ret = 0;
//    for(int i = 0 ; i < 9; ++i){
//        if((1<<i) & bitmask) ++ret;
//    }

    while(bitmask){
        bitmask &= (bitmask-1);
        ++ret;
    }

    return ret;


}




int candidates[10][46][1024];

void generateCandidates(){
    memset(candidates, 0, sizeof(candidates));

    for(int set = 0; set < 1024; set +=2){
        // set에 대해 set으로 만들 수 있는 sum,

        int l = getNum(set);
        int s = getSum(set);
        int subset = set;
        while(true){
            candidates[l][s][subset] |= (set & ~subset);
            if(subset == 0) break;
            subset = (subset-1) & set;
        }
    }
}


void put(int r, int c, int val){
    for(int h = 0 ; h< 2; ++h){
        known[hint[r][c][h]] += (1<<val);
    }
}
void remove(int r, int c, int val){
    for(int h = 0 ; h< 2; ++h){
        known[hint[r][c][h]] -= (1<<val);
    }

}

int getCandHint(int hint){
    return candidates[length[hint]][sum[hint]][known[hint]];

}


int getCandList(int r, int c){
    return getCandHint(hint[r][c][0]) & getCandHint(hint[r][c][1]);

}
bool search(){
    // 아직 숫자가 쓰이지 않은 흰 칸 중 후보의 수가 최소인 칸을 찾는다.

    int minR = -1;
    int minC = -1;
    int minCands= 1023;


    for(int r = 0; r < N; ++r)
        for(int c = 0; c < N; ++c)
            // 현재 (r, c) 에 쓰일 수 있는 값들을 비트 마스크로 나타낸다. 1~9 다 쓸 수 있으면 111 111 111
            // 현재 흰색이고, 아직 아무것도 안 쓰인 pos 라면,
            if(color[r][c] and value[r][c] == 0){
                int cand = getCandList(r, c);
                if(getNum(minCands) > getNum(cand)){
                    minCands = cand;
                    minR = r;minC = c;
                }
            }

    // r, c 가 white이고 value[r][c]가 0 인데, 여기에 아무것도 쓸 수 있는 게 없다면 return false;


    if(minCands == 0) return false;

    if(minR == -1){
        printSolution();
        return true;
    }

    for(int val = 1; val <= 9; ++val){
        if(minCands & (1<<val)){
            put(minR, minC, val);

            if(search()) return true;
            remove(minR, minC, val);
        }
    }
    return false;


}

int getLength(int row, int col, int dir){

    // dir == 0 가로
    int length= 0;
    if(dir == 0){
        for(int s = col+1; s < N; ++s){
            if(color[row][s] == 1)
                ++length;
            else
                break;
        }

    }
    else{
        for(int s = row+1; s < N; ++s){
            if(color[s][col] == 1)
                ++length;
            else
                break;
        }


    }

    return length;



}
int main() {

    cout << getSum(15) << " " << getNum(15) << endl;

    ifstream inFile;
    inFile.open("../input");
    inFile>>T;
    for(int test_case = 0; test_case < T; ++test_case){
        inFile>> N;
        memset(color, 0, sizeof(int) * MAX_N * MAX_N);
        memset(value, 0, sizeof(int) * MAX_N * MAX_N);
        memset(length, 0, sizeof(int) * MAX_N * MAX_N );
        memset(known, 0, sizeof(int) * MAX_N * MAX_N);
        memset(hint, 0, sizeof(int) * MAX_N * MAX_N * 2);


        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                inFile>> color[r][c];
            }
        }

        inFile>> Q;
        for(int q = 0; q <Q ;++q){
            int row; int col;
            inFile>> row; inFile >> col;
            row-=1; col -=1;
            int dir ; inFile >> dir;
            inFile>>sum[q];
            hint[row][col][dir] = q;
            // (getLength(row, col, dir)

            length[q] = getLength(row, col, dir);

        }


        generateCandidates();
        search();


    }






    return 0;
}