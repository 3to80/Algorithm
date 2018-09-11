#include <iostream>
#include <list>

using namespace std;

int N;
int K;


struct ListNode{
    ListNode *prev;
    ListNode *next;
    int val;
    ListNode(ListNode *prev , ListNode *next, int val){
        this->prev = prev; this->next = next; this->val = val;
    }
};
struct List{

    ListNode *begin;
    ListNode *end;
    int cnt;

    List(){
        this->cnt= 0;
        this->begin = NULL;
        this->end   = NULL;
    }

    void insert(int val){

        if(cnt == 0){
            begin = new ListNode(NULL, NULL, val);
            end = begin;
            cnt +=1;
            return;
        }
        ListNode *newone = new ListNode(NULL, NULL, val);
        end->next = newone; newone->prev = end;
        newone->next = begin;end = newone;
        begin->prev = end;
        cnt += 1;
    }
    void discard(ListNode *target){
        if(target == NULL) return;
        if(cnt == 1){
            begin = NULL; end = NULL;
            cnt = 0;
            return;
        }

        target->prev->next = target->next;
        target->next->prev = target->prev;
        if(target == begin) begin = begin->next;
        else if(target == end) end = end->prev;

        cnt -= 1;
    }
    ListNode *move(ListNode *target, int K){

        for(int i = 0; i < K; ++i) target = target->next;

        return target;
    }


};

int T;
int func(int N, int K){
    // N 명의 사람과 K 번째 skip을 하며 죽일 때 마지막까지 살아있는 사람의 번호를 구해라
    if(N == 1) return 1;

    return (func(N-1, K ) + K-1)% N + 1;


}
int main() {
//    cout << func(40,3);

    cin >> T;
    for(int t = 0 ; t < T; ++t){
        cin >>N; cin >> K;
        List li = List();
        for(int i = 0; i < N; ++i) li.insert(i+1);

        ListNode *iter = li.begin;
        while(li.cnt > 2){
            li.discard(iter);
            iter = li.move(iter, K);
        }
        iter = li.begin;
        for(auto i = 0; i< li.cnt; ++i){
            cout<< iter->val << " ";
            iter = iter->next;

        }


    }

    return 0;
}


