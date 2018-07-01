from collections import deque
from collections import defaultdict
from collections import Counter

## string 만들어도 쉼표 이런걸로 구분만해도 되는 문제였잖아..
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:

    def makeHashmap(self, root, hashmap):
        if root:
            if not hashmap.get(root.left):
                self.makeHashmap(root.left, hashmap)
            L = hashmap.get(root.left)
            if not hashmap.get(root.right):
                self.makeHashmap(root.right, hashmap)
            R = hashmap.get(root.right)

            hashmap.update({root: (root.val, L , R)})

    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNodev
        :rtype: List[TreeNode]
        """
        counter = Counter()
        hashmap = defaultdict()
        hashmap.update({None : "#"})
        ret = []
        queue = deque()
        queue.append(root)

        while queue:
            target = queue.pop()

            if not hashmap.get(target.left):
                self.makeHashmap(target.left, hashmap)

            L = hashmap.get(target.left)

            if not hashmap.get(target.right):
                self.makeHashmap(target.right, hashmap)

            R = hashmap.get(target.right)

            tmp = {target: (target.val, L, R)}
            hashmap.update(tmp)
            counter[tmp[target]] += 1
            if counter[tmp[target]] == 2:
                ret.append(target)
            if target.left:
                queue.appendleft(target.left)
            if target.right:
                queue.appendleft(target.right)

        print(hashmap)
        return ret

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(4)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    root.right.left.left = TreeNode(4)

    root.right.right = TreeNode(4)

    s = Solution()
    for i in s.findDuplicateSubtrees(root):
        print(i.val)

