/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 // base, iter, end case 에 대해 꼼꼼히 체크하기.
 // 각 step 별 data들과 data update에 대해 명확한 정의
 
 */
class Solution {

    public ListNode getMiddlePoint(ListNode head){
        ListNode ret, aux;
        ret = head ; aux = head;
        while(aux.next !=null && aux.next.next != null){
            aux = aux.next.next;
            ret = ret.next;
        }
        return ret;
    }
    public void reverseList(ListNode head){
        ListNode curr = head.next.next;
        ListNode prev = head.next;
        while(curr != null){
            ListNode cn = curr.next;
            ListNode tmp  = head.next;
            head.next = curr;
            prev.next = cn;
            curr.next = tmp;
            curr = cn;   
        }        
    }
    
    public void shuffle(ListNode head, ListNode middle){
        ListNode tp = head; ListNode prevq = middle;
        ListNode tq = middle.next;
        while(tq != null ){
            ListNode pn = tp.next;
            ListNode qn = tq.next;
            tp.next = tq;
            if(prevq != tp){
                prevq.next = tq.next;
                tq.next = pn;                           
            }
            tp = pn;
            tq = qn;
            
        }
    }    
    
    public void print(ListNode head){
        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }
    public void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null)return;
        
        ListNode middle = getMiddlePoint(head);
        // System.out.println(middle.val);
        // print(head);
        reverseList(middle);        
        // print(head);
        shuffle(head, middle);
        // print(head);
        
    }
}
