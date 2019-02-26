#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int C;
int N;
const int ANUM = 26;


int getOverlap(const string& cur, const string& next){
    int ret = 0;
    for(int i = 0; i < cur.size(); ++i){
        if(cur[i] == next[i]) ++ret;
        else break;
    }
    return ret;
}



vector<bool> visited;
vector<vector<int>> edge;

int flag = 0;
void dfs(int node, vector<bool> &currentpath, vector<int> &ret){
    visited[node] = true;
    currentpath[node] = true;

    int check  =0;
// 다음에 할 거를 찾는다.
    for(int i = 0 ; i < edge[node].size(); ++i){
        int nextcand = edge[node][i];
        if(currentpath[nextcand]){
            // cycle이 발생한거
            flag = 1;
            return;
        }
        if(not visited[nextcand])
            dfs(nextcand, currentpath, ret);
    }
    if(check == 0){
//        cout << node<< " endl " << endl;
        ret.emplace_back(node);
    }




}

vector<int> getTopological(const vector<vector<int>> &edge){
    // 현재 edge 에 대해 topology를 만들어보기
    vector<int> ret;

    // 전체 component들 모두를 순회하기 위해 사

    for(int i = 0; i < ANUM; ++i){
        if(not visited[i]){
            // i를 포함하는 component 내에서 cycle이 발생하는지 알아보기 위해 사용.
            vector<bool> currentpath(ANUM, false);
            dfs(i, currentpath, ret);
            if(flag == 1){
                ret.clear();
                return ret;
            }
        }
    }

    reverse(ret.begin(), ret.end());
    return ret;
}


void print(const vector<int> &s){
    for(auto i : s){
        cout<< (char)('a'+i);
    }
    cout<<endl;
}

bool is_include(int t, const vector<int> &list1){

    for(int i =0 ; i < list1.size(); ++i){
        if(t == list1[i]) return true;
    }
    return false;

}
int main() {
    freopen("../input", "r" , stdin);
    cin>>C;
    for(int i = 0; i < C; ++i){
        // 안쓰이는거는 false
        // 쓰인거는 true

        visited.clear();
        edge.clear();
        for(int i = 0 ; i < ANUM;++i) visited.emplace_back(false);
        for(int i = 0 ; i < ANUM;++i) edge.emplace_back(vector<int>());

        flag = 0;
        cin >> N;

        string current; cin>>current;
        string next;

        for(int n = 1; n < N; ++n){
            cin>>next;
            // current 단어와 next단어가 겹치는 정도를 반환한다.
            int overlap = getOverlap(current, next);
//            cout<<current << " " << next << " " << overlap << endl;

            // current 전체가 다 overlap이면 얻을 수 있는 정보가 없으니 continue
            if(overlap == current.size()) continue;
            // current[overlap] 과 next[overlap]은 겹치지 않는 가장 첫 지점
            // 방향은 cur->next가 되어야 한다.
            // (current[overlap] - 'a', next[overlap]- 'a') 라는 edge가 만들어진다.
            int curnode = current[overlap] - 'a';
            int nextnode = next[overlap] - 'a';

            if(not is_include(nextnode, edge[curnode]))
                edge[curnode].push_back(nextnode);
            current = next;
        }
//        vector<int> t_ret;

        vector<int> t_ret= getTopological(edge);
        if(t_ret.empty())cout<<"INVALID HYPOTHESIS" <<endl;
        else print(t_ret);


    }


    return 0;
}