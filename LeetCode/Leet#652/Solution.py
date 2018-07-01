import collections

def findDuplicateSubtrees(root):


    newdict = collections.defaultdict(lambda : "")
    newdict[None] = "null"


    def trv(root):
        if not root: return "null"
        struct = "%s,%s,%s" % (str(root.val), trv(root.left), trv(root.right))
        nodes[struct].append(root)
        return struct

    nodes = collections.defaultdict(list)
    trv(root)

    return [nodes[struct][0] for struct in nodes if len(nodes[struct]) > 1]

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None



class Solution(object):


    def findDuplicateSubtrees(self, root):
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__

        count = collections.Counter()
        ans = []

        def lookup(node):
            if node:
                uid = trees[(node.val, lookup(node.left), lookup(node.right))]
                count[uid] += 1
                if count[uid] == 2:
                    ans.append(node)
                return uid
        lookup(root)

        return ans


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(4)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    root.right.left.left = TreeNode(4)
    root.right.right = TreeNode(4)
    # for i in findDuplicateSubtrees(root):
    #     print(i.val)


    s= Solution()
    for i in s.findDuplicateSubtrees(root):
        print(i.val)
