# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # What if the BST is modified (insert/delete operations) often
    # and you need to find the kth smallest frequently?
    # How would you optimize the kthSmallest routine?

    def __init__(self, array = []):
        # python에서 ArrayList가 구현된게 따로 있는지 화인
        self.arr = array
        self.root = None

    def update_arr(self, val):
        pass

    def insert(self, val):
        # val을 tree에 넣음
        self.updateArr(val)
        pass

    def delete(self, val):
        # val을 tree에 넣음
        self.updateArr(val)
        pass

    def lmr(self, node, li, k):
        if node is None:
            return
        self.lmr(node.left, li, k)

        li.append(node.val)
        if len(li) == k:
            return
        self.lmr(node.right, li, k)

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """

        # Tree 안쓰고 MinHeap, MaxHeap 으로 만들어서 하기
        li = []
        self.lmr(root, li, k)
        return li[k-1]



