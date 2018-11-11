/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;



struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};





class Solution {
public:

    void print(ListNode *itm, int k){
        int cnt = 0;
        while( itm ){
            if(cnt == k) break;
            cout<<itm->val << " ";
            itm = itm->next;
            ++cnt;
        }
        cout << endl;
    }


    void print(ListNode *itm){
        while( itm ){
            cout<<itm->val << " ";
            itm = itm->next;
        }
        cout << endl;
    }
    ListNode *makeTest(int n){
        ListNode *ret = new ListNode(0);
        ListNode *cur = ret;
        for(int i = 1; i < n ; ++i, cur = cur->next){
            cur->next = new ListNode(i);
        }

        return ret;

    }


    // Solution 1.
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


int main(){
    Solution s;
    ListNode *target = s.makeTest(10);
    s.print(target);

    s.print(s.reverseKGroup(target , 2));


    return 0;
}