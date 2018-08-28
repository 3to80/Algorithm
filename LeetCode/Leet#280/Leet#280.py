class Solution:
    def swap(self, arr, idx1, idx2):
        tmp = arr[idx1]
        arr[idx1] = arr[idx2]
        arr[idx2] = tmp

    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        for i in range(len(nums) - 1):
            if i % 2 == 0 and nums[i] > nums[i + 1]:
                self.swap(nums, i, i + 1)
            if i % 2 == 1 and nums[i] < nums[i + 1]:
                self.swap(nums, i + 1, i)