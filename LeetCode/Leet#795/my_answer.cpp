class Solution {
public:

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0; int rs = 0; int small = 0;
        for(int i = 0 ; i < A.size(); ++i){
            if(A[i] >= L and A[i]<=R){
                small = 0;
                ans +=(i-rs)+1;
            }
            else if(A[i]< L){
                small +=1;
                ans += (i-rs) + 1 - small;
            }else{
                small = 0;
                ans = ans;
                rs = i+1;
            }
            
        }
        
        
        
        return ans;
    }
};

