/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 * Time O(n)
 * Space O(n)
 */
class Solution {
    
    public int getLength(ListNode head){
        int len = 1;
        while(hasNext(head)){
            len++;
            head = head.next;
        }
        return len;
    }
    
    public boolean hasNext(ListNode head){
        return ((head == null) || (head.next == null))?false:true;
    }
    
    public Stack<ListNode> makeStack(ListNode head, int len){
        int cnt = 0;
        Stack<ListNode> ret = new Stack<>();
        ret.push(null);
        
        while(head != null){
            if(len %2 == 0){
                if(cnt >= len/2) ret.push(head);
            }else{
                if(cnt > len/2) ret.push(head);    
            }
            
            cnt++;
            head = head.next;
        }
        return ret;
    } 
    
    
    public void reorderList(ListNode head) {
        if(head == null)return;
        int len = getLength(head); // 절반이상인 것만 저장
        Stack<ListNode> stack = makeStack(head, len);
        
        System.out.println(stack.size());
        ListNode cur = head;
        
        
        while(!stack.isEmpty()){
          
            ListNode itm = stack.peek();
            stack.pop();
            ListNode curNext = cur.next; 
            cur.next = itm;
            if(itm == null)break;
            itm.next = curNext;
            cur = curNext;
        }
        
        
        
        
        
    }
}
