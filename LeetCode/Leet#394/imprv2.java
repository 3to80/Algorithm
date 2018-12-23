class Solution {
    /*
    String 형태 -> iteration으로 자르는걸 생각해보기.         
    func decode(str) : [sidx, str.length() ) 까지의 STRING을 DECODE하는 함수 
    
    
    TIME COMPLEXITY : O(N)
    SPACE COMPLEXITY : worst O(N)
    */
    private int sidx = 0;

    public StringBuilder decode(StringBuilder s){
        StringBuilder ret = new StringBuilder();
        while(sidx < s.length() && s.charAt(sidx) != ']'){
            
            //get prefix 
            if(Character.isAlphabetic(s.charAt(sidx))) ret.append(s.charAt(sidx++));
            else{
                // get product number
                int num = 0;
                while(Character.isDigit(s.charAt(sidx)))
                    num = num*10 + Character.getNumericValue(s.charAt(sidx++));

                // iteration 
                sidx++;
                StringBuilder tmp = decode(s);
                sidx++;
                while(num-- > 0)
                    ret.append(tmp);


                
            }
            
        }

        
        return ret;

    }    
    public String decodeString(String s) {    
        
        StringBuilder sb = new StringBuilder(s);
        StringBuilder ret = decode(sb);
        return ret.toString();    
    }
        
        
        
    
}


