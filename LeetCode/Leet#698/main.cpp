
const int MAXMAP = (1 << 16);
const int N = 16;

int TARGET;

bool ret[MAXMAP][N];
bool check[MAXMAP][N];

class Solution {
public:
    
    // ref vector<int> &nums 
    // init set <- (1 << nums.size()) , 비트 인덱스가 nums.size() 보다 작은 값들에 대해, 1이면 쓸 수 있는거 0이면 못쓰는거
    // init num <- K , 만들어야되는 수
    // K가 총 만들어져야 되는 subset의 수
    // sum이 주어진 배열에 대해 그 합
    
    
    int getSum(const vector<int> &nums, int subset){
        int sum = 0;
        for(int i = 0 ; i < nums.size(); ++i){
            if((1<<i) & subset){
                sum += nums[i];
                
            }
        }
        return sum;
    }

    bool func(int set, int k, const vector<int>& nums){
        if(check[set][k]) return ret[set][k];

        check[set][k] = true;

        
        if(k ==0) return true;
        if(set == 0) return false;
        // bool ret = false;        
        for(int subset = set; subset > 0; subset = (set & (subset-1))){
            if(getSum(nums, subset) == TARGET){
                ret[set][k] |= func((set & ~subset), k-1, nums);  
                if(ret[set][k])break;
            }
        }
        return ret[set][k];
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(ret, false, sizeof(bool) * N * MAXMAP);
        memset(check, false, sizeof(bool) * N * MAXMAP);

        int sum = 0;
        for(auto i: nums) sum += i;
        if(sum% k != 0) return false;
        int set = (1 << nums.size()) -1;        
        
        TARGET = sum/k;
        
        return func(set, k, nums);
        
        
        
    }
};
