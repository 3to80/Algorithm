####Problem
Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.

#####Note

- - -
####Solution

1) Post order로, 각 node들은 자기가 subtree의 root일 떄, leaf까지의 최단 거리를 기록
2) Pre order로 내려오며, 자기가 subtree root일 때 최단거리와 parent을 이용한 최단거리를 비교 
3) k일 때 값을 return 
- problem :  항상 필요없는 모든 노드들을 다 뒤져야하고, 항상 저장도 다 해야함
  
Leet solution:
   
- Undirected graph라 생각하고, leaf를 먼저 구함. O(n)
- leaf들에 대해, BFS를 해 target이 먼저 나오면 answer 
- 최악의 경우 O(n) , O(n)이지만 target 값에 따라 훨씬 빠르게 나올 수 있음. 

- - - 
####Analysis
Time complexity
- O(n)

Space complexity
- O(n)
- - -
####Discussion
- - -
####Reference