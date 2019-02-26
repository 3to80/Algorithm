#include <iostream>
#include <stdio.h>
#include <vector>



using namespace std;

int C;
int N;
int M;
int L;
int R;


struct DisjointSet{
    vector<int> parent, rank, size, enemy;

    explicit DisjointSet(int n):parent(n), rank(n, 0), size(n, 1), enemy(n, -1){
        for(int i = 0; i < n ; ++i) parent[i] = i;
    }

    int find(int u){
        if(u == parent[u]) return u;
        //path compression
        return parent[u]=find(parent[u]);
    }
    int merge(int u, int v){
        //merge를 진행하지 않는 경우
        if(u == -1 or v == -1){
            return max(u, v);
        }
        int u_root = find(u);
        int v_root = find(v);
        if(u_root == v_root) return v_root;
        // merge를 수행해야 하는 경우

        if(rank[u_root] > rank[v_root])swap(u_root, v_root);
        // v_root 를 위로 진행
        // rank, parent, size
        if(rank[u_root] == rank[v_root])rank[v_root]++;
        parent[u_root] = v_root;
        size[v_root] += size[u_root];
        return v_root;
    }
    // u와 v가 동지이다. 모순이 일어나면 true, 모순이 일어나지 않으면 false
    bool ack(int u, int v){
        // 모순 체크 : u, v가 다른 편집기를 쓰고 있다면 모순
        // 그렇다면 u와 v는 적대 관계에 놓였다는 거니까 이 경우만 제외 하면 된다.
        // 이 경우를 제외 하면
        // u, v합친다.
        // 동지의 적은 나의 적이다라는 논리에 입각, 이 집합들과 적대적인 관계의 집합들도 합친다.
        // 그리고 결과적으로 얻는 두 집단에 생기는데 이 두 집단을 서로 적대 표현하면 된다.

        u = find(u); v = find(v);
        if(enemy[u]== v) return true;

        int new_one = merge(u, v);
        int new_enemy = merge(enemy[u], enemy[v]);
        enemy[new_one]= new_enemy;
        if(new_enemy != -1) enemy[new_enemy] = new_one;
        return false;

    }
    // u와 v가 적이다. 모순이 이러나면 true, 모순이 일어나지 않으면 false
    bool dis(int u, int v){
        // 나의 적은 나의 동료이다
        u = find(u); v= find(v);
        // u와 v가 적이 아니라면 모순
        if(u == v) return true;
        // 적의 적은 나의 동지
        int a = merge(u, enemy[v]); int b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return false;


    }

};

int getMaxParty(const DisjointSet &buf){
    int ret = 0;
    for(int node =0; node < N; ++node){

        if(buf.parent[node] == node){
            int enem = buf.enemy[node];
            if(enem > node)continue;
            int mysize = buf.size[node];
            int enemSize = (enem == -1 ? 0 : buf.size[enem]);
            ret += max(mysize, enemSize);
        }
    }

    return ret;
}

int main() {

    freopen("../input", "r", stdin);

    cin >> C;
    for(int c = 0; c < C ;++c){

        cin >>N; cin >> M;
        DisjointSet dset(N);
        bool flag = false;
        for(int i = 0; i < M; ++i){
            string cmd; cin>>cmd;
            cin>>L; cin >> R;
            // 여기서 함수로 생각해야 되는데..
            // 코드가 복잡해지면 그 순간 나도 뭐하는지 까먹게 됨
            if(cmd[0] =='A') flag= dset.ack(L, R);
            else flag = dset.dis(L, R);
            if(flag){

                cout << "CONTRADICTION AT " << i+1 << endl;

                break;
            }
        }
        if(not flag)cout << "MAX PARTY SIZE IS " << getMaxParty(dset) << endl;

    }

    return 0;
}