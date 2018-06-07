####Problem

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.


Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
#####Note
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

- - -

#### Test

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

####Solution

1) LMR으로 list 만들고 거기서 출력 

2) 추가 문제, 삭제와 삽입이 빈번한 경우 kth smallest 찾기
 - 각 treeNode에, 자기보다 작은 것이 몇개 있는지, 자기보다 큰 것이 몇 개 있는지를 기록한다. (각 smallNum, bigNum)
 - insert 혹은 delete 할 때, 변경되는 node들에 대해 update를 같이 해준다.  
    * insert: current node에 보다 큰 값이면, current의 right로 가고 current의 bigNum을 +1 해준다 
    * 그럼 이 때 영향 받는 모든 node들의 값을 update 해줘야 한다. 그럼 insert의 시간복잡도가 update 하는 과정이 포함되어 상당히 나빠진다. 
    * 특히 delete 하는 경우, 영향받는 노드가 삭제되는 거의 위쪽으로 값 갱신이 필요하기 때문에 cost가 커질 수 있따. 
 = > 다른 방법

2-2) Tree에 모든 값들이 정렬되어 있는 list를 하나 만든다. 이 list는 항상 정렬된 상태이다.     
    -> 만약 리스트를 ArrayList로 구현했다고 하면..  
    - insert해서 어떤 값이 들어오면 tree와 list 모두 갱신한다   
        -> insert cost + list update cost  
            -> list update cost : 분할 상환을 하면 O(1)  
    - delete해서 어떤 값이 제거되면 tree와 list 모두 갱신한다  
        -> delete cost + list update cost  
            -> list update cost : 분할 상환을 하면 O(1)
    - kth smallest를 찾으면 이 list에서 k번째 작은 값을 찾으면 된다. -> O(1)   
    


- - - 
####Analysis
Time complexity
2번 방법 : O(k), 1번도 유사할 
Space complexity
2번 방법: O(n)

- - -
####Discussion
- - -
####Reference