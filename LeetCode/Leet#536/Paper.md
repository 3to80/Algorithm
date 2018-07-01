####Problem

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

           4
         /   \
        2     6
       / \   / 
      3   1 5   
  

Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".


#####Note

- - -
####Solution
  
My solution

- Stack을 이용
- s에 대해 for iteration을 하며, 
    0) default: stack에는 TreeNode("") 이 들어 있음
    1) 0-9 or - 인 경우, stack의 top의 값을 update
    2) ( : stack의 top을 새로 만들면, 이전 top의 left가 null 이면 top.left= new TreeNode("") right도 비슷하게
    3) ) : 인 경우 pop

Leet solution

-  유사



- - - 
####Analysis
My solution

- Time complexity
    - top의 string update일 때 += 로 하지 않고 while로 0-9 - 인 부분 찾아서 한번에 update 치면 O(n)

- Space complexity
    - stack사용하는데 필요, 최대 (개수랑 비례해서 필요하고, ( 는 최대 n개를 넘을 수 없기 때문에 O(n) 

Leet solution

- Time complexity

- Space complexity


- - -
####Discussion

- for iteration에서 초기값 못잡고 버벅 거리는 경우가 계속 발생
- 예제에 대해서 동작정의를 더 꼼꼼하게 하자. 
- - -
####Reference