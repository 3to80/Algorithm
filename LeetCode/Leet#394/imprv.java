class Solution {
    /*
    String 형태 -> iteration으로 자르는걸 생각해보기.         
    func decode(str, sidx, eidx) : [sidx,eidx) 까지의 STRING을 DECODE하는 함수 
    
        - 앞으로 차례차례 자른다/ 
        string ret:=""
        string head:=""
        int num:=0

        while str[sidx] is alphabet : 
            head.append(str[sidx])
            sidx++

        while str[sidx] is number:
            num = 10 * num + number(str[sidx])
            sidx++
        
        // sidx : 최초의 [ 위치, 이거에 대응하는 ]를 찾는다.
        next = sidx와 대응되는 ]의 위치
        - stack으로 [랑 ]를 체크 -> 함수 호출 마다 eidx 찾는 작업이 들어간다. (중복)
            => 처음에 한번 돌며, 각 [에 대해 대응되는 ]의 좌표를 저장한다. 
            ret = head + num *decode(str, sidx+1, next+1) +decode(str, next+1, eidx)
    
    TIME COMPLEXITY : O(N)
    SPACE COMPLEXITY : O(K), K는 [] 쌍의 개수, K < N
    */
    
    private StringBuilder prod(StringBuilder target, int num){
        if(num <= 0) throw new IllegalArgumentException("Argument 'num' is not postive number");        
        
        StringBuilder ret = new StringBuilder(target.length() * num);
        for(int i = 0; i < num ; ++i) ret.append(target);
        return ret;
    }

    public StringBuilder decode(StringBuilder s, int start, int end, HashMap<Integer, Integer> hm){
        StringBuilder ret = new StringBuilder();
        int num = 0;                
        int sidx = start;

        //get prefix 
        while(sidx < end && Character.isAlphabetic(s.charAt(sidx)))
            ret.append(s.charAt(sidx++));
                    
        // get product number
        while(sidx < end && Character.isDigit(s.charAt(sidx)))
            num = num*10 + Character.getNumericValue(s.charAt(sidx++));
     
        // iteration 
        // ret = head + num *decode(str, sidx+1, next+1) +decode(str, next+1, eidx)
        if(sidx < end && s.charAt(sidx) == '['){
            int closed_idx = hm.get(sidx);
            ret.append(prod(decode(s, sidx+1, closed_idx, hm), num));
            ret.append(decode(s, closed_idx+1, end, hm));
        }
        
        return ret;

    }    
    public String decodeString(String s) {    
        // 열린 대괄호에 대해 대응되는 닫는 대괄호 위치 저장
        HashMap<Integer, Integer> aux_hm = new HashMap<>();
        Stack<Integer> aux_stack = new Stack<Integer>();
        for(int i = 0; i < s.length(); ++i){            
            if(s.charAt(i) == '[') aux_stack.push(i);
            else if(s.charAt(i) == ']'){
                aux_hm.put(aux_stack.peek(), i);
                aux_stack.pop();                
            }
        }
        
        StringBuilder sb = new StringBuilder(s);
        StringBuilder ret = decode(sb, 0, sb.length(), aux_hm);
        return ret.toString();    
    }
        
        
        
    
}


