


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Time Complexity : O(n) 
Space Complexity : O(1)
*/


class Solution {
public:

    ListNode *get_end_node(ListNode *pick, int target){
        ListNode *ret = pick;
        for(int i = 0; i < target; ++i){
            if(ret == nullptr)break;
            ret = ret->next;
        }
        return ret;
    }

    void swap(ListNode *head, ListNode *tail, int k){
        for(int j = 0; j < k-1; ++j){
            ListNode *tmp = head->next;
            head->next = tail->next;
            tail->next= head;
            head= tmp;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail= get_end_node(head, k-1);
        if(tail == nullptr)return head;
        else{
            ListNode *next = reverseKGroup(tail->next, k);
            swap(head, tail, k);
            head->next = next;
            return tail;
        }
    }

};
