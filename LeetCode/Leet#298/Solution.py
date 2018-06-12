class Solution:
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        max_len=1
        if root:
            stack=[[root,1]]
            while stack:
                temp=stack.pop()
                node, count = temp[0], temp[1]
                left, right = node.left, node.right

                if left:
                    temp=[left,1]
                    if node.val+1==left.val:
                        temp[1]=count+1
                    #이전 값을 계속 가지고 있으면 상관없네
                    stack.append(temp)
                if right:
                    temp=[right,1]
                    if node.val+1==right.val:
                        temp[1]=count+1
                    stack.append(temp)
                if max_len<count:
                    max_len=count
            return max_len

        return 0
