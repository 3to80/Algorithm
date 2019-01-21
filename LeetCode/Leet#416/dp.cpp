const int MAX_NUM = 201;
const int MAX_VAL = 101;
const int MAX_SUM = MAX_NUM * MAX_VAL ;

int aux[MAX_SUM][MAX_NUM];
int aux2[MAX_SUM];


class Solution {
public:
    int sum(const vector<int>& nums){
        int ret = 0;
        for(const auto &i : nums)
            ret += i;
        return ret;
    }
    int func(int T, int lim, const vector<int> &nums){
        /*
        @Input
            - T : int, Targetval
            - lim : int, [0, lim) 
        @Output
            - int, [0, lim)까지만을 사용했을 때 T를 만들어 낼 수 있는지를 반환
        @Logic
            1. base
                func(0, anyvalue) 는 항상 1
                func(postive value, 0) 는 항상 0
            
            2. recursion
                func(T, lim) = funct(T, lim-1) || func(T-nums[lim-1], lim-1) 
            
        */
        if(lim < 0 or T <0) return 0;
        
        // cout << T << " " << lim << endl;
        int &ret = aux[T][lim];
        
        if(T == 0) return ret= 1;
        if(T > 0 and lim == 0) return  ret= 0;

        if(ret != -1) return ret;
        
        return  ret= (func(T, lim-1, nums) || func(T-nums[lim-1], lim-1, nums));
        
    }
    bool canPartition(vector<int>& nums) {
      
        int S = sum(nums);
        if( S%2 != 0) return false;
        S /= 2;
 
        memset(aux2, 0, sizeof(int) * MAX_SUM);
        aux2[0] = 1;
        
        for(int k = 1; k < nums.size(); ++k){
            for(int i = S ; i >0 ; --i){
                if(i >= nums[k])
                    aux2[i] = aux2[i] || aux2[i-nums[k]];
            }
            
        }

        return aux2[S] == 1; 
        
    }
};
