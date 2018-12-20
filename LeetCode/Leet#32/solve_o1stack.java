class Solution {
    public int longestValidParentheses(String s) {
        /*
        Time complexity : O(n)
        Space complexity : O(n)
        */
        
        int stacknum = 0;
        int aux[] = new int[s.length()];     
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) == ')'){
                if(stacknum > 0){
                    stacknum--;
                    aux[i] = 1; 
                }
            }
            else stacknum++;
        }
        
        int tmp = 0;
        for(int i = s.length()-1 ; i >-1; --i){
            if(aux[i] == 1) tmp++;
            else{
                if(tmp > 0){
                    aux[i] = 1;
                    tmp--;
                }
            }            
        }
        int best = 0;
        int local = 0;
        for(int i = 0 ; i <s.length(); ++i){
            if(aux[i] == 0){
                best = (best < local)?local:best;
                local = 0;
            }
            else local++;
        }
    
        best = (best < local)?local:best;
        
        return best;        
    }
}
