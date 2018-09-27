#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;


int C;
int N;




vector<int> kmpSearch(const string &H, const string &N);
vector<int> getPartialMaxMatched(const string &N, int matched){
    int m = N.size();
    vector<int> pi(m, 0);

    for(int begin = 1; begin < m ; ++begin){
        for(int i =0; i +begin < m; ++i){
            if(N[begin+i] != N[i]) break;
            pi[begin+i]= max(pi[begin+i], i+1);
        }

    }
    return pi;
}




int shifts(const string &original, const string& target){
    return kmpSearch(original+original , target)[0];
}


int main() {


    freopen("../input.txt", "r", stdin);
    cin>> C;
    for(int test_case = 0; test_case < C; ++test_case){
        cin >> N;
        string current; cin >> current;
        int ans = 0;
        for(int n = 0; n < N; ++n){
            string target; cin >> target;
            int move = (n%2 == 0)? -1:1;
            if(move == -1) ans += shifts(target, current);
            else ans += shifts(current, target);
            current = target;
        }

        cout << ans << endl;
    }

    return 0;
}

vector<int> kmpSearch(const string &H, const string &N){
    auto h = H.length(); auto n = N.length();
    int begin= 0;
    vector<int> ret;
    int matched = 0;
    vector<int> pi= getPartialMaxMatched(N, matched);

    while(true){
        //must be {begin + h < h }
        if(begin + n -1 >= h) break;
        if(matched < n and H[begin + matched] == N[matched]){
            matched ++;
            if(matched == n) ret.emplace_back(begin);
        }



        else{
            if(matched > 0){
                int maxPartialMatched = pi[matched-1];
                begin += matched - maxPartialMatched;
                matched = maxPartialMatched;
            }
            else begin ++;

        }
    }
    return ret;
}