const int MAX_SUM = 1001;

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int T = S + sum;
        // 불가한 경우 
        if(T%2 == 1 || S > sum) return 0;
        // 리스트에서 특정 원소들을 골라 합이 특정 값이 되게 하는 것의 개수를 구하기.
        T /= 2;
        int aux[MAX_SUM] = {0};
        aux[0] = 1; // DP[0][0] = 1 로 정의
    
        
        for(int i = 1; i < nums.size()+1; ++i){
            // 방향 주의, NUMS[i-1]부터 시작해버리면, 갱신하는 과정에서, 이전에 갱신된 값이 다시 들어옴
            for(int subsum = T; subsum > nums[i-1]-1 ; --subsum){
                aux[subsum] = aux[subsum] + aux[subsum - nums[i-1]];
            }
        }
        return aux[T];   

    }
    
    
};

