class Solution {
    // n이 주어졌을 때, 노드가 n개 있는 bst의 개수는 ? 
public:
    
    

    int func(vector<int> &aux, int n){
        int &ret = aux[n]; 
        if(ret != -1) return ret;

        if(n == 0) return ret = 0;
        if(n == 1) return ret = 1;
        
        ret = 2 * func(aux, n-1);
        
        for(int i = 1; i < n-1; ++i){
            ret += func(aux, i) * func(aux, n-1 -i);
        }
        return ret;
    }
    
    int numTrees(int n) {
        vector<int> aux(n+1, -1);
        
        
        
        
        
        return func(aux, n);
        
        
        
    }
};
