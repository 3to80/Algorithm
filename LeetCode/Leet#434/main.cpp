class Solution {
public:
    int countSegments(string s) {
        int ret = 0;      
        bool prevSpace = true;
        for(int i = 0;  i < s.size(); ++i){
            if(prevSpace and s[i] != ' '){
                prevSpace= false;
                ++ret;
            }
            else if(not prevSpace and s[i] == ' ')
		prevSpace = true;
            
            
            
        }
        return ret; 
    }
};
