const int MIN = -987654321;

// const int MAX = 1001;
// int arr[MAX][MAX];

class Solution {
public:
    
//     int search(vector<int> &nums, map<int, int> &aux, int val){
//         auto iter = aux.find(val);
//         if(iter == aux.end()) return -1;
//         return iter->second;
//     }
    
//     int g(vector<int> &nums, map<int, int> &aux, int p, int pp){
//         int &ret = arr[p][pp];
//         if(ret != -1) return ret;        
//         ret = 0;
//         int diff = nums[p] - nums[pp];
//         if(diff >= nums[pp]) return 0;
//         int sidx = search(nums, aux, diff);
//         if(sidx == -1) return 0;
//         ret =  g(nums, aux, pp, sidx)+1;
        
//         return ret;
//     }
    
//     int f(vector<int> &nums,map<int, int> &aux,  int idx){
        
//         int maxValue = MIN;
//         for(int prev = idx-1; prev > -1; --prev){
//             int diff = nums[idx] - nums[prev];
//             if(diff >= nums[prev]) break;
//             int pp_idx = search(nums, aux, diff);
//             if(pp_idx == -1) continue;
//             maxValue = max(maxValue, g(nums, aux,  prev, pp_idx)+1);            
//         }
        
        
        
//         if(maxValue == MIN) return 0;
//         return maxValue;
//     }
    
    
    
    
//     int lenLongestFibSubseq(vector<int>& A) {
//         map<int, int > aux;
//         for(int i = 0 ; i< A.size(); ++i)
//             aux.insert(make_pair(A[i], i));
//         memset(arr, -1, sizeof(int) * MAX * MAX);
        
        
//         int maxValue = MIN;
//         for(int i = 0 ; i < A.size(); ++i)
//             maxValue = max(maxValue, f(A, aux,  i));

//         return (maxValue == 0)? 0: (maxValue+2);
        
//     }
    
    
    
    
    
    int lenLongestFibSubseq(vector<int>& A) {
        map<int, int > aux;
        for(int i = 0 ; i< A.size(); ++i)
            aux.insert(make_pair(A[i], i));
            
        vector<vector<int> > dp(A.size(), vector<int>(A.size(), 2));
        
        int maxValue = MIN;
        
        //DP[i][j] : A[i]에서 시작해 A[j] 로 끝날 때 가장 긴 길이 
        
        //DP[i][j] = max(DP[i][j] , DP[i][k] +DP[k][j] -1), j > k > i, A[k] == A[j] - A[i]에 대해  

        
        for(int i = 0; i < A.size() - 1; ++i){
            for(int j = i+1; j < A.size(); ++j){
                if (aux.find(A[j]-A[i]) != aux.end() and aux[A[j] - A[i]] < i){
    				dp[i][j] = max(dp[i][j], dp[aux[A[j] - A[i]]][i] + 1);                   
                    maxValue = max(maxValue, dp[i][j]);

                }
            }
            
        }
        
        
        return (maxValue==2 or maxValue == MIN)?0:(maxValue);
        
    }
    
    
    
};
