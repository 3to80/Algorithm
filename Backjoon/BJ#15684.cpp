#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;


// aux[r][c] 는 r-1 번째 가로줄 , c-1번째 세로줄 점에 가로작대기가 달렸는지 안달렸는지를 나타낸다.

int aux[30][10];
//true 이면 가로줄이 달린거

int N;
int M;
int H;

int candNum(){
    int ret = 0;
    for(int r = 0; r < H; ++r){
        for(int c = 0; c < N; ++c){
            if(aux[r][c])continue;
            if(c-1 >= 0 and aux[r][c-1]) continue;
            if(c == N-1) continue;
            ++ret;
        }
    }
    return ret;
}


int traverse(int r, int c, bool dir){
    if(r == H) return c;

    if(not aux[r][c]) return traverse(r+1, c, false);
    if(dir and aux[r][c]) return traverse(r+1, c, false);
    if(not dir and c+1 < N and aux[r][c+1] and aux[r][c]){
        if(aux[r][c] == 1)return traverse(r, c+1, true);
        if(aux[r][c] == 2)return traverse(r, c-1, true);
    }

    if(not dir and c-1 >= 0 and aux[r][c-1] and aux[r][c]) {
        if(aux[r][c] == 1)return traverse(r, c+1, true);
        if(aux[r][c] == 2)return traverse(r, c-1, true);
    }
}

bool check(){
    for(int i = 0 ; i < N; ++i){
        int dest = traverse(0, i, false);
        if(dest != i) return false;
    }
    return true;

}

int g(int n){
    if(candNum() < n) return -1;
    if(n ==0){
        if(check())return 0;
        return -1;
    }

    for(int r = 0; r < H; ++r){
        for(int c = 0; c < N; ++c){
            // 놓을 수 있는 점들을 거른다 .
            if(aux[r][c])continue;
            if(c >= N-1) continue;
            if(aux[r][c+1]) continue;
            // 놓을 수 있는 점들에 대해 하나 선택.  r, c
            aux[r][c] = 1;
            aux[r][c+1] = 2;

            int ret = g(n-1);
            if(ret != -1) return ret+1;
            aux[r][c] = 0;
            aux[r][c+1] = 0;

        }
    }

    return -1;
}
int f(int n){
    // n개의 작대기를 추가 했을 때 답이 나오는가?
    if( n > 3 ) return -1;
    if(candNum() < n) return -1;
    int ret = g(n);
    if(ret != -1) return ret;
    return f(n+1);
}


int main(){
    ifstream inFile;
    inFile.open("../input");
    inFile >> N;
    inFile >> M;
    inFile >> H;
//    cin >> N;
//    cin >> M;
//    cin >> H;
    memset(aux, 0, sizeof(int) * 30 * 10);


    for(int m = 0; m < M; ++m){
        int colNum; int rowNum;
        inFile >> rowNum; inFile >> colNum;
        aux[rowNum-1][colNum -1] = 1;
        aux[rowNum-1][colNum] = 2;
    }



//

//    cout << candNum()<<endl;
//
//    return f(0);
    cout << f(0) << endl;
    return 0;


}


