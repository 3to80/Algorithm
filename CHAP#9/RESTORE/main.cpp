#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

int TEST_CASE;
int K;
vector<string> WORDS;
const int MAX = 987654321;

const int MAXK = 16;
const int MAXVISIT = (1<<16);
int cache[MAXK][MAXVISIT ];


int overlap(const string &front, const string &rear ){
    int i= 0; int j = 0;
    int ret = 0;
    while(i != front.size() and j != rear.size()){
        if(front[i] == rear[j]){
            i++; j++;
            ret++;
        }
        else{
            ret = 0;
            j = 0;
            ++i;
        }
    }
    return ret;


}
int overlap(int i , int j){

    return overlap(WORDS[i], WORDS[j]);
}



int solve(int here, int visited){
    int &ret = cache[here][visited];
    if(ret != -1)return ret;

    if(visited == ((1 << WORDS.size()) -1)){
        return (ret = 0);
    }

    ret = 0;

    // 00010 , 방문하지 않은 i를 찾아야 한다. visited의 i번째 값을 가져와야 된다.
//    int maxValue = -1;
    for(int i = 0; i < WORDS.size(); ++i){
        if((visited & (1 << i)) == 0){
            cout << WORDS[here] << " " << WORDS[i]<<endl;
            cout<<overlap(here, i)<<endl;
            ret = max(ret, solve(i, visited + (1<<i)) + overlap(here, i));

        }

    }

    return ret;
}

string reconstruct(int here, int visited){
    if(visited == (1 << WORDS.size())-1){

        return WORDS[here];
    }
    for(int next = 0; next < WORDS.size(); ++next){

        if(visited & (1<<next)) continue;

        int ifUsed = solve(next, visited + (1<<next)) + overlap(here, next);

        if(solve(here, visited) == ifUsed){
            cout<<WORDS[here] << " " << WORDS[next] << endl;
            cout<< "overlap : " << overlap(here, next)<<endl;
            cout << WORDS[here].substr(0, WORDS[here].size() - overlap(here, next)) << endl;
            return (WORDS[here].substr(0, WORDS[here].size() - overlap(here, next))+ reconstruct(next, visited + (1<<next)));
        }

    }
    return "qwer";

}



int solve(){

    int maxValue = -1;

    int pick = -1;
    for(int start = 0; start < WORDS.size(); ++start){
        int tmp = solve(start, (1<<start));
        if(maxValue < tmp){
            maxValue = tmp;

            pick = start;
        }
//        maxValue = max(solve(start, (1<<start)), maxValue);

    }
    return pick;

}


int main() {




    ifstream inFile;
    inFile.open("../input");
    inFile >> TEST_CASE;

    for(int t = 0 ; t < TEST_CASE; ++t){
        inFile >> K; // 1<= K <= 15
        vector<string> sliceSet;
        for(int k = 0; k < K; ++k){
            string tmp;inFile >> tmp;
            bool flag = true;

            for(int i = 0 ; i < sliceSet.size(); ++i){
                int t  = sliceSet[i].find(tmp);
                if(t != -1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                sliceSet.emplace_back(tmp);
            }

        }

        //####

        // solve(const vector<string> &sliceSet); // sliceSet들을 조합했을 때 가장 길이가 짧은 문자열을 출력한다.

        memset(cache, -1, sizeof(int) * MAXK * MAXVISIT);
        WORDS = sliceSet;
        int maxStart = solve();
        cout<< solve() << endl;
        cout<< " 답 " <<reconstruct(maxStart, (1<< maxStart))<<endl;

    }



    return 0;
}