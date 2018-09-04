// parenthesis 에서 open brackets 들어오는걸, 그만큼의 closed brackets 이 들어온다고 생각 


class Solution {
public:
    bool isValid(string s) {
       stack<char> myStack;
        for(int idx = 0; idx < s.size(); ++idx){
            switch(s[idx]){
                    case('('):
                        myStack.push(')');
                        break;
                    case('{'):
                        myStack.push('}');
                        break;
                    case('['):
                        myStack.push(']');
                        break;
                default:
                    if(myStack.empty() or myStack.top() != s[idx]) return false;
                    myStack.pop();

                    
                    
            }
            
        }
        
        return myStack.empty();
    }
    
};
