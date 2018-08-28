#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;



int N; // 음악의 수
const int MAXN= 51;
int K;// K분후의 음악을 들음
const int  MAXK = 1000001;
int M; // 좋아하는 곡목의 수
const int MAXM = 11;
double MATRIX[MAXN][MAXN];


double CACHE[5][MAXN];


vector<int> playlist;

vector<int> preference;



 // index 연산안에 modular 들어가서 헤맴, 항상 모듈된 idx를 다뤄야되는데 그냥 값을 다뤄서 원하는 동작이 안 된줄 알고 어 이게 뭦 싶었음. 심지어 실수는 확인하는 과정의 print..
void solve(){


    CACHE[0][0] = 1;





    for(int time = 1; time < K+1; ++time){
        for(int current_song = 0; current_song < N; ++current_song){
            CACHE[time%5][current_song] = 0;
            for(int prev_song = 0; prev_song < N; ++prev_song){
                double tmp = CACHE[(time - playlist[prev_song])%5][prev_song] * MATRIX[prev_song][current_song];

                CACHE[time%5][current_song] += tmp;



            }


        }

    }




}



int main() {


    ifstream inFile;
    inFile.open("../input");
    int T ; inFile>>T;

    for(int t = 0; t < T; ++t){
        inFile >> N;
        inFile >> K;
        inFile >> M;
        playlist.clear(); preference.clear();
        for(int i = 0; i < N; ++i){
            int l; inFile >> l;
            playlist.emplace_back(l);
        }
        memset(MATRIX, 0, sizeof(double) * MAXN * MAXN);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c) {
                double tmp;inFile >> tmp;
                MATRIX[r][c] = tmp;
            }
        }
        for(int i = 0 ; i < M ; ++i){
            int tmp = 0; inFile >> tmp;
            preference.emplace_back(tmp);
        }


        memset(CACHE, 0, sizeof(double)*5 * MAXN);

        solve();
        for(int idx = 0; idx < preference.size(); ++idx){
            //preference[idx]
            double ret = 0;
            int cur_pref_song = preference[idx];
            for(int dx = 0; dx < playlist [ cur_pref_song]; ++dx){
                ret += CACHE[(K - dx)%5][cur_pref_song];
            }

            cout<<ret<<" ";
        }
        cout<<endl;

    }





    return 0;
}