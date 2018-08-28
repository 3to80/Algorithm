# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        if not s:
            return None

        ret = TreeNode("")
        stack = list()
        stack.append(ret)

        for i in range(0, len(s)):
            top = stack[-1]
            if s[i] == '(':
                if not top.left:
                    top.left = TreeNode("")
                    stack.append(top.left)
                else:
                    top.right = TreeNode("")
                    stack.append(top.right)

            elif s[i] == ')':
                stack.pop()

            else:
                top.val += s[i]

        return stack[-1]


if __name__ == '__main__':
    root = TreeNode(-13)
    root.right = TreeNode(6)
    s = Solution()
    a = s.str2tree('1()(2)')
    print(s.str2tree('1()(2)'))
