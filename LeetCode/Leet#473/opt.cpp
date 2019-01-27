// Simple dfs에서 시작
// pruning을 사용해보자 

int TARGET;
class Solution {
public:
    
    
    bool func(vector<int> &sub, int idx, const vector<int>& nums){
        if(idx == nums.size())
            return sub[0] == sub[1] and sub[1] == sub[2] and sub[2] == sub[3];

         for (int i = 0; i < 4; ++i) {
            if(sub[i] + nums[idx] > TARGET) continue; // continue이지 
            
            bool flag = true;
            for(int j = i-1; j > -1; --j){
                if(sub[i] == sub[j]){
                    flag = false;
                    break;
                }
                
            } 
             
            if(not flag)continue;
            sub[i] += nums[idx]; 
            if (func(sub, idx+1, nums)) return true;
            sub[i] -= nums[idx];
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        
        int n = nums.size();
        if(n ==0) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%4 != 0) return false;
        int T = sum/4;
        TARGET = T;
        // vector<int> sub(size_t size) , vector<int sub(size_t size, int init_val)
        // 내림차순 정렬
        sort(nums.begin(), nums.end(), greater<int>());
         // sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});

        vector<int> sub(4);
        return func(sub, 0, nums);
                    
            
        
    }
};
