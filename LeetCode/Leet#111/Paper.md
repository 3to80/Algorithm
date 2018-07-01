####Problem

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

#####Note


- - -
####Discussion

- Leaf Node 란 조건 깜빡
- f(node)라는, binary tree 타는 함수의 경우,
    1) node가 None
    2) node가 있고 node.left, node.right 둘다 None
    3) node.left, right 중 하나만 None *2
    4) "
    5) node 있고 자식 둘다 있을 때

5가지 경우 생각

- - -
####Reference