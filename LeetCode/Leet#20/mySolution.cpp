class Solution {
public:
    bool isValid(string s) {
       stack<char> myStack;
        for(int idx = 0; idx < s.size(); ++idx){
            if(s[idx] == '(' or s[idx] == '{' or s[idx] == '[') myStack.push(s[idx]);
            else{
                if(myStack.empty()) return false;
                if(
                    not(
                    myStack.top() == '(' and s[idx] == ')' or 
                    myStack.top() == '{' and s[idx] == '}' or
                    myStack.top() == '[' and s[idx] == ']' 
                    )
                  )return false;
                else{
                    myStack.pop();
                }
                
            }
            
        }
        
        return myStack.empty();
    }
    
};
