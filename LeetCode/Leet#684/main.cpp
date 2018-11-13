

class DisjointSet{
public:    
    vector<int> parent;
    vector<int> count;
    
    DisjointSet(int N){
        parent = vector<int>(N+1, 0);
        count = vector<int>(N+1, 1);
        for(int i = 0; i < N; ++i)parent[i+1]=i+1;
    }
    void merge(int u, int v){
        int pu = find(u); int pv = find(v);     
        if(count[pu] < count[pv]){
            int tmp = pu;
            pu = pv;
            pv = tmp;
        }
        count[pu] += count[pv];
        parent[pv] = pu; 
    }
    int find(int u){
        if(parent[u] == u) return parent[u];
        return parent[u] = find(parent[u]);
    }    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {        
        DisjointSet dset = DisjointSet(edges.size());
        vector<int> ret;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            // Disjoint Set에 넣는다. 
            if(dset.find(u) != dset.find(v)) 
                dset.merge(u, v);
            else{
                ret.emplace_back(u);
                ret.emplace_back(v);
                break;
            }
        }
        return ret;
    }
};
