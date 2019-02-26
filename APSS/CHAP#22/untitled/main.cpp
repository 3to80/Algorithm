#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;

     freopen("../input", "r", stdin);

    unordered_map<int, int> hashmap;
    cin >> n;
    string line;
    bool flag = false;
    getline(cin, line);  // drop a newline traling n
    vector<int> cand;
    set<int> answer;
    while (n-- > 0) {
        getline(cin, line);  // drop a newline traling n
        stringstream ss(line);
        //임시로 받아오는데 사용
        vector<int> aux;
        for (int fork; !(ss >> fork).fail(); )
            aux.emplace_back(fork);

        for(int i = 0 ; i < aux.size() -1; ++i){
            if(hashmap.count(aux[i]) == 0)hashmap.insert(make_pair(aux[i], aux[i+1]));
            else{
                if(hashmap[aux[i]] != 0 and hashmap[aux[i]] != aux[i+1])
                    flag = true;
            }
        }
        cand.emplace_back(aux[aux.size()-1]);

        if(flag) break;
    }
    // cand와 hashmap을 이용해서 마지막 것들을 찾는다.


    if(flag) cout << -1 << endl;
    else{
        for(int i = 0; i< cand.size(); ++i){
            //cand[i]가 키 속에 있으면 넘어간다.
            if(hashmap[cand[i]] == 0)
                answer.insert(cand[i]);
        }

        for(auto i = answer.begin(); i != answer.end(); ++i){
            cout << *i << " ";
        }

    }

    // @todo Write your code here.
    return 0;
}
