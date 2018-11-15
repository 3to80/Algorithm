/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*

2개의 pointer를 이용한다.
2개의 pointer를 이용하여 같이 iteration 시키면, 두 node간의 node 차이가 특정 값을 가지게 하여 이동시킬 수 있다. 

*/

class Solution {
public:
    //1 path
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        1->2->3->4->5, and n = 2.
              a
        t     a          
           t     a
              t     a
        a의 next가 null이면 t->next에 대한 조정을 한다 
              
        */
        
        ListNode *aux = head;        
        for(int i = 0; i < n; ++i) aux = aux->next;
        ListNode *target = head;
        if(aux == NULL) return head->next;    
                
        while(aux->next != NULL){
            target = target->next;
            aux = aux->next;
        }
        
        ListNode *prev= target;
        ListNode *discard = prev->next;
        if(discard){
            prev->next = discard->next;
            delete discard;
        }
        return head;

    }

    
    
    // 2 path stack
    
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // 전체 길이를 모르는 경우 어떻게 할 수 있을 까 
//         // 스택 같은데 다 집어 넣는거면 2 pass 겠지? 
//         stack<ListNode *> aux;
        
//         ListNode *iter = head;
//         while(iter){
//             aux.push(iter);
//             iter = iter->next;
//         }
            
//         for(int i = 0; i < n ; ++ i) aux.pop();
        
//         if(aux.empty()){
//             ListNode *discard = head;
//             head = head->next;
//             delete discard;
//             return head;
        
//         }
        
        
//         ListNode *prev = aux.top();

//         ListNode *discard = prev->next;
//         prev->next = discard->next;
//         delete discard;
//         return head;
        
        
        
        
//     }

    
    

};
