#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>


using namespace std;

int C;
int N;
int p;
int q;


bool is_dominated(const map<int, int> &tree, int p, int q){
    auto dom = tree.lower_bound(p); // p보다 큰 것 중 가장 왼쪽에 있는 것
    if(dom == tree.end()) return false;
    return dom->second > q;
}


void removeDominated(map<int, int> &tree, int p, int q){

    auto it= tree.lower_bound(p);
    //it부턴 안봐도 된단거

    // 가장 왼쪽에 있는 점이니 지울 필요가 없다.
    if(it == tree.begin()) return;
    it--;
    while(true){
        if(it->second > q) break;
        if(it == tree.begin()){
            tree.erase(it);
            break;
        }
        else{
            auto discard = it;
            --it;
            tree.erase(discard);
        }
    }
}


int main() {

    freopen("../input", "r", stdin);
    cin >> C;
    for(int c = 0; c < C; ++c){

        cin >> N;

        map<int, int> tree;

        int ans = 0;

        for(int n = 0; n < N; ++n){
            cin>>p; cin>>q;
            // (p, q)가 지배 당하는지 먼저 확인한다.
            if(not is_dominated(tree, p, q)){
                // (p,q)가 지배하는 점이 있다면 제거 한다.
                removeDominated(tree, p, q);
                // (p, q)를 tree에 넣는다.
                tree.insert(make_pair(p, q));
            }
            ans += tree.size();
        }
        cout<<ans<<endl;
    }





    return 0;
}


