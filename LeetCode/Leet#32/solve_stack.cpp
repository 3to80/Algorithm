class Solution {
public:
    
    
    int longestValidParentheses(string s) {
        
        if(s.size() == 0) return 0;
        
        
        vector<bool> aux(s.size(), true);
        
        stack<int> pStack;
        
        for(int i = 0 ; i < s.size(); ++i){            
            if(!pStack.empty() and s[i] == ')' and s[pStack.top()] == '(') pStack.pop();
            else pStack.push(i);                
        }
        
        while(not pStack.empty()){
            int target = pStack.top();
            pStack.pop();
            aux[target] = false;
        }
        

        int maxValue = 0;
        int cand = 0;
        
        for(auto i: aux){
            if(i){
                cand +=1;
                maxValue = max(maxValue, cand);
            }
            else cand = 0;
            
        }
        
        
        
        
        return maxValue;
        
        
    }
};
