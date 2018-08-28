#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;


int T;

const int MAXN = 101;
int N;
vector<int> num;

int main() {

    ifstream inFile;
    inFile.open("../input");


    inFile >> T;

    for(int test_case = 0; test_case < T ; ++test_case){
        num.clear();
        inFile >> N;


        for(int i = 0; i < N; ++i){
            int tmp; inFile >> tmp;
            num.emplace_back(tmp);
        }
        int ans = 0;

        priority_queue<int, vector<int>, greater<int> > pq;

        for(int i = 0; i< N; ++i)
            pq.push(num[i]);

        while(pq.size() > 1){
            int min1 = pq.top(); pq.pop();
            int min2 = pq.top(); pq.pop();
            pq.push(min1+min2);
            ans += min1+min2;
        }


        cout<<ans<<endl;


    }




    return 0;
}