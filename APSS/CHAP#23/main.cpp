#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;


int C;
int N;
int seedA;
int seedB;
const int MOD = 20090711;

void printMax(const priority_queue<int, vector<int>, less_equal<int> > &heap){
    cout<<"MAXHEAP ";

    priority_queue<int, vector<int>, less_equal<int> > tmp(heap);
    while(not tmp.empty()){
        int target = tmp.top();
        cout << target << " ";
        tmp.pop();
    }
    cout<<endl;
}
void printMin(const priority_queue<int, vector<int>, greater<int> > &heap){
    priority_queue<int, vector<int>, greater<int> > tmp(heap);
    cout<<"MINHEAP ";

    while(not tmp.empty()){
        int target = tmp.top();
        cout << target << " ";
        tmp.pop();
    }
    cout<<endl;
}

struct RNG{
    int seed,a, b;
    RNG(int _a, int _b): a(_a), b(_b), seed(1983){}
    int next(){
        int ret = seed;
        seed = ((seed * (long long)a) + b)%MOD;
        return ret;
    }


};
int main() {
    freopen("../input", "r", stdin);

    cin >> C;
    for(int c = 0; c < C; ++c){
        cin >> N;cin >> seedA; cin >> seedB;
        priority_queue<int, vector<int>, less_equal<int> > maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;


        int n = 0;
        typedef long long ll;
        ll val = 1983;
        ll ans = 1983;
        RNG rng(seedA, seedB);
        rng.next();
        maxHeap.push(val);
        for(int n = 0 ; n < N-1; ++n){
            val = rng.next();
            maxHeap.push(val);
            if(minHeap.size() > 0 and maxHeap.top() > minHeap.top()){
                int tmp1 = maxHeap.top();
                maxHeap.pop();
                int tmp2 = minHeap.top();
                minHeap.pop();
                minHeap.push(tmp1);
                maxHeap.push(tmp2);
            }
            if(maxHeap.size() == minHeap.size()+2){
                int tmp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(tmp);
            }

            // get Medium
            ans = ((ans+ maxHeap.top())%MOD);
        }
        cout << ans << endl;

    }

    return 0;
}