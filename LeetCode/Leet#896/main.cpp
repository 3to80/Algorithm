class Solution {
public:
    

    bool isMonotonic(vector<int>& A) {
        
        int dir = 0;
        // dir == 0, 이전 지금 똑같은거
        // dir == 1 , 증가
        // dir == -1, 감소
        
        for(int i = 0; i< A.size() ; ++i){
            if(i == 0 or A[i-1] == A[i]) continue;
            if(A[i-1]< A[i]){
                if(dir == -1) return false;
                dir = 1;
            }
            if(A[i-1] > A[i]){
                if(dir == 1) return false;
                dir = -1;
            }
            
            
        }
        return true;


        
    }
};
