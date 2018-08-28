# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# buildNode(nums) : using binary search method

class Solution(object):
    def buildNode(self, start, end, arr):
        if end - start >= 1:
            mid = start + (int)((end - start) / 2)
            ret = TreeNode(arr[mid])
            ret.left = self.buildNode(start, mid, arr)
            ret.right = self.buildNode(mid + 1, end, arr)
            return ret
        else:
            return None

    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None

        return self.buildNode(0, len(nums), nums)








