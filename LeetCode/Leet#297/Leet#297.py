# Definition for a binary tree node.
from collections import deque

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return '#'
        else:
            return '{},{},{}'.format(str(root.val), self.serialize(root.left), self.serialize(root.right))


    def buildTree(self, nodes):
        target = nodes.popleft()
        if target == '#':
            return None
        else:
            t = TreeNode(target)
            t.left = self.buildTree(nodes)
            t.right = self.buildTree(nodes)

        return t

    def deserialize2(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        words = data.split(",")
        a = deque(words)
        return self.buildTree(a)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        words = data.split(",")

        if words[0] == '#':
            return None

        ret = TreeNode(words[0])
        stack = [{'Node': ret, 'status': 0}]


        for i in range(1, len(words)):
            top = stack[-1]
            if words[i] == '#':
                # left를 못 쓰게 만든다.
                if top['status'] == 0:
                    top['status'] = 1
                else:
                    stack.pop()
            else:
                if top['status'] == 0:
                    top['Node'].left = TreeNode(words[i])
                    top['status'] = 1
                    stack.append({'Node': top['Node'].left, 'status': 0})
                else:
                    top['Node'].right = TreeNode(words[i])
                    stack.pop()
                    stack.append({'Node': top['Node'].right, 'status': 0})
        return ret



# 1,5 ,#,#,2,3,#,#,4,#,#
# 2 1 # # 3 # #

#        1 0     1 1       1 2              3 0    3 1       3 2
# 2 0 -> 2 0 ->  2 0  -> | 2 0  => 2 1 | -> 2 1 -> 2 1 -> |  2 1 -> 2 2





if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(2)

    s = Codec()
    print(s.serialize(root))
    # print(s.serialize(root))
    f = s.deserialize2(s.serialize(root))
    print(f)

