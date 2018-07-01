####Problem


#####Note

- - -
####Solution
  
My solution

- 
-

Leet solution

- 
-




- - - 
####Analysis
My solution

- Time complexity

- Space complexity

Leet solution

- Time complexity

- Space complexity


- - -
####Discussion

<pre><code>
재귀로 짰을 때 :
    def hasPathSum(self, root, sum):
        if not root and not sum: # 잘못 생각한 조건
            return False
        if root and not root.left and not root.right and root.val == sum:
            return True
        if root:
         # 너무 성급하게 조건을 다 따지려고 한다. 결국 root 가 null인걸로 가기 때문에 맞는 case를 한번더 풀어재껴서 꼬인듯
         # 끝나는 조건에 대해 고찰이 부족했다. 
            a = b = False
            if root.left:
                a = self.hasPathSum(root.left, sum-root.left.val)
            if root.right:
                b = self.hasPathSum(root.right, sum-root.right.val)
            if not a and not b:
                return False

수정:

    def hasPathSum(self, root, sum):
        if not root:
            return False
        if root and not root.left and not root.right and root.val == sum:
            return True
        if root:
            return self.hasPathSum(root.left, sum-root.left.val) or self.hasPathSum(root.right, sum-root.right.val)

</pre></code>


- Queue를 안쓰고 재귀로 하려고 할 때 문제점
    - True일 때만 Return을 하고 종료를 해야 되는데, 재귀로 할 때 False인 경우 계속해서 진행하게 하는데 어려움
    - Recursive하게 하는 법

- 꼬이면 End section이 제대로 되어있는지부터 확인해보자. 보통 나갈 때 조건에 빠트린 것이 있거나, end에 대한 고찰이 부족해 한 번 더 꼬은 경우이다. 



- - -
####Reference