class Solution {
    
    /*

    buffer를 둔다.
    전체를 훑으며 buffer는 항상 더한다. 
    [ 이면 braceCheck ++, ]이면 braceCheck--;
    
    braceCheck가 0이이 되는 순간, buffer에 모아왔던 값들에 대해 [[]] 를 decode하고 그 값을 결과값에 더한다. 
    TimeComplecxity : O( ? ) // n0 ~ nk-1 까지 k개가 있을 때, 각 부분에 대해, recursive의 깊이를 곱하는거
    
    최소 O(N), 최대 O(N^2) 근데 평균이 O(N)쪽에 가깝게.. 분석
    
    SpaceComplexity ; O(N) // buffer가 최대 O(N) // 재귀할 때 space complexity
    

    개선 필요, RECURSIVE 하는쪽을 중복으로 보고 있음
    */
    
    StringBuilder prod(StringBuilder target, int num){
        if(num <= 0) throw new IllegalArgumentException("Argument 'num' is not postive number");        
        StringBuilder ret = new StringBuilder(target.length() * num);
        for(int i = 0; i < num ; ++i)
            ret.append(target);
        return ret;
    }

    // [sidx, eidx) 까지 에 대해 decode 시키는거 , 항상 
    public StringBuilder decode(StringBuilder s, int sidx, int eidx){
        StringBuilder ret = new StringBuilder();
        StringBuilder buffer = new StringBuilder();
        int num = 0;        
        int braceCheck = 0;
        
        for(int i = sidx; i < eidx; ++i){
            char cur = s.charAt(i);
            if(Character.isAlphabetic(cur)) ret.append(cur);
            else if(Character.isDigit(cur)) num = num*10 + Character.getNumericValue(cur);
            else{
                int braceStack = 0;
                int iterstart= i;
                braceStack++;
                i++;
                while(braceStack != 0){
                    buffer.append(s.charAt(i));
                    if(s.charAt(i) == '[') braceStack++;
                    else if(s.charAt(i) == ']') braceStack--;
                    i++;
                }

                ret.append(prod(decode(buffer, 0, buffer.length()-1), num));
                
                num = 0;
                buffer.replace(0, buffer.length(), "");
                i--;
            }
        }
        return ret;

    }    
    public String decodeString(String s) {    
        StringBuilder sb = new StringBuilder(s);
        StringBuilder ret = decode(sb, 0, sb.length());
        return ret.toString();    
    }
        
        
        
    
}


