####Problem

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:
<pre><code>
   1
    \
     3
    / \
   2   4
        \
         5
</code></pre>

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:
<pre><code>
   2
    \
     3
    / 
   2    
  / 
 1
</code></pre>

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

#####Note

- - -
####Solution

각 노드에 대해서 Iteration을 한다.

<pre> <code>


max_val, Queue 
Queue <- {"node": root, "len": 1}
while Queue:
    target <- Queue.pop()
    left, right = target[node].left, target[node].right

    CASE #1, left, right 모두 None
        # 더 이상 갈곳이 없으니 max_val update만 하면 된다.
        update(max_val, target["len"]

    CASE #2, left만 None
        # right 자식이랑 더 이어지는지, 안 이어지는지 체크한다.
        1) 이어지는 경우
            target node를 right, 길이를 1 추가 
        2) 이어지지 않는 경우, 새로운 시작이 될 수도 있는 right를 다시 넣어준다.
            update(max_val, target["len"]
            Queue.add(rightNode, init_len)
    
    CASE #3, right만 None
        # left 자식이랑 더 이어지는지, 안 이어지는지 체크한다.
        1) 이어지는 경우
            target node를 left, 길이를 1 추가 
        2) 이어지지 않는 경우, 새로운 시작이 될 수도 있는 right를 다시 넣어준다.
            update(max_val, target["len"]
            Queue.add(rightNode, init_len)


    CASE #4, left, right 모두 Not none
        # right 자식이랑 더 이어지는지, 안 이어지는지 체크한다.
        1) 이어지는 경우
            Queue.add(right, target(len)+1)        
        2) 이어지지 않는 경우, 새로운 시작이 될 수도 있는 right를 다시 넣어준다.
            update(max_val, target["len"]
            Queue.add(rightNode, init_len)
    
    
        # left 자식이랑 더 이어지는지, 안 이어지는지 체크한다.
        1) 이어지는 경우
            target node를 left, 길이를 1 추가 
            Queue.add(right, target(len)+1)

        2) 이어지지 않는 경우, 새로운 시작이 될 수도 있는 right를 다시 넣어준다.
            update(max_val, target["len"]
            Queue.add(rightNode, init_len)



</code></pre>
- - - 

####Analysis
Time complexity
 - Queue를 돌며 모든 Node를 다보고, 자기의 child만의 관계를 비교하기 대문에
    -> O(n)


Space complexity
 - Queue를 채울 때 Space가 필요하고, BFS이기 때문에 한번에 최대 들어가는 양은 BinarySearch에서 O(n/2)이 될 것이다
    -> O(n/2)
- - -
####Discussion
- - -
####Reference