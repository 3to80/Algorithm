# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


from collections import deque


class Solution:

    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        queue = deque()
        queue.append([root, sum])
        while queue:
            target = queue.pop()
            if target[0].val == target[1] and not target[0].left and not target[0].right:
                return True
            else:
                if target[0].left:
                    queue.append([target[0].left, target[1] - target[0].val])
                if target[0].right:
                    queue.append([target[0].right, target[1] - target[0].val])

        return False

        # def hasPathSum(self, root, sum):
        #     if not root and not sum:
        #         return False
        #     if root and not root.left and not root.right and root.val == sum:
        #         return True
        #     if root:
        #         a = b = False
        #         if root.left:
        #             a = self.hasPathSum(root.left, sum-root.left.val)
        #         if root.right:
        #             b = self.hasPathSum(root.right, sum-root.right.val)
        #         if not a and not b:
        #             return False












