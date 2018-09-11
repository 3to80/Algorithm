const int NUM = 26;

int cnt[NUM];
int cons[NUM];

class Solution {
    
    
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        int idx = 0;
        memset(cnt, -1, sizeof(int)*NUM);
        memset(cons, -1, sizeof(int) * NUM);        
        
        for(auto i : tasks){
            if(cnt[i-'A'] == -1) {
                cnt[i-'A'] = 1;   
                cons[i-'A'] = 0;
            }
            else cnt[i-'A']++;
            
        }
        
        int TOTAL = tasks.size();

        while(TOTAL){
            
            int maxVal= -1;
            int maxChar = -1;

            
            
            // 현재 idx보다 작거나 같은 거리에 대해             
            for(int i = 0; i < NUM; ++i){
                if(cons[i] > -1 and cons[i] <= idx and cnt[i] >0){
                    if(maxVal < cnt[i]){
                        maxVal = cnt[i];
                        maxChar = i;
                    }
                }
            }
            
            // cout << "#" << maxChar << endl;
            if(maxChar == -1){

                int minValue = 897654321;
                for(int i = 0; i < NUM; ++i){
                    if(cnt[i] >0){
                        minValue = min(minValue, cons[i]);
                    }   
                }

                idx = minValue;
                continue;
            }
            
            cnt[maxChar]--;
            cons[maxChar] += (n+1);
            idx++;
            TOTAL -= 1; 
            
            
        }
        
        return idx;
        
        
    }
};
