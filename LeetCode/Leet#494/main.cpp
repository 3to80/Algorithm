const int PAD = 2001 ;
int aux[PAD * 2][21];
class Solution {
public:
    void recursion(vector<int> &nums, int S, int i, int target, int& ret){
        if(nums.size() == i){
            if(target == S) ret+=1;
            return;
        }
        else{
            recursion(nums, S, i+1, nums[i]+target, ret);
            recursion(nums, S, i+1, -1 * nums[i]+target, ret);            
        }
    }
    
    int recursion2(vector<int> &nums, int S, int idx){
        int &ret = aux[S+PAD][idx];
        if(ret != -1) return ret;
        
        if(idx == 0){
            if(S == 0) return ret= 1;
            else return ret= 0;
        }
        else return ret=(recursion2(nums, S -nums[idx-1], idx-1) + recursion2(nums, S+nums[idx-1], idx-1));
    }
    int sum(vector<int>& nums){
        int ret = 0;
        for(auto i : nums)ret += i;
        return ret;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        // int ret = 0;
        // recursion(nums, S, 0, 0, ret);
        // return ret;
        int sumnums = sum(nums);
        if(sumnums < S) return 0;
        if(-sumnums > S) return 0;
        memset(aux, -1, sizeof(int) * PAD * 2 * 21);
        return recursion2(nums, S, nums.size());
    }
    
    
};
