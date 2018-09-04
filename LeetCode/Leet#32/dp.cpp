
class Solution {
public:
    
    
    int endIdx(const string& s, vector<int> &aux, int idx){
        // s[idx]에서 끝나는 valid parenthesis 길이
        int &ret = aux[idx];
        if(ret != -1) return aux[idx];
        if(idx < 1) return ret = 0;
        
        
        if(s[idx] == '(') return ret = 0;
        
        if(s[idx-1] == '(') return ret = (endIdx(s, aux, idx-2) + 2);
        
        if(s[idx - endIdx(s, aux, idx-1)-1] == '(')
            return ret = ( endIdx(s, aux, idx-1) + 2 
                          + 
                          endIdx(s, aux, idx-endIdx(s, aux, idx-1) -2));
            
        

        return ret = 0;

    }
    int longestValidParentheses(string s) {

        if(s.size() < 2) return 0;
        
        vector<int> aux(s.size(), -1);
        if(s.substr(1).compare("()") == 0)aux[1] = 2;
        for(int i = 0 ; i < s.size(); ++i) endIdx(s, aux, i);
        
        int maxValue = 0;
        for(auto i : aux) maxValue = max(maxValue, i);
        return maxValue;
        
        
    }
};
