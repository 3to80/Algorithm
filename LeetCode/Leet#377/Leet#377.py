class Solution:
    def findMaxIndex(self, nums, target):
        # target보다 크지 않은 최대 index
        idx = 0
        for i in nums:
            if i <= target:
                idx += 1
            else:
                return idx -1
        return idx -1

    def findMaxIndex_bin(self, nums, start, end,  target):
        # binarySearch를 이용해보자
        if end-start < 1:
            return -1
        if target > nums[-1]:
            return len(nums) - 1
        mid = int((start + end)/2)
        if nums[mid] > target:
            if mid >= 1 and nums[mid-1] <= target:
                return mid-1
            return self.findMaxIndex_bin(nums, start, mid, target)

        elif nums[mid] < target:
            if mid+1 < len(nums) and nums[mid+1] > target:
                return mid
            return self.findMaxIndex_bin(nums, mid + 1, end, target)

        else:
            return mid


    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #Exception
        if not nums or target < min(nums):
            return 0

        nums.sort()
        min_val, max_val = nums[0], nums[-1]
        # Common case
        # Init
        # 1) find max val
        # i_max = self.findMaxIndex(nums, target)
        i_max = self.findMaxIndex_bin(nums, 0, len(nums), target)

        nums = nums[0:i_max+1]
        # 2) dp init, dp[0]는 1로 해줘야 되나?

        dp = [0] * (target + 1)
        dp[0] = 1
        for i in nums:
            dp[i] = 1
        # Iteration
        for curr in range(min_val+1, target+1):
            for i in nums:
                if curr-i > 0:
                    dp[curr] += (dp[curr - i])
                else:
                    break

        return dp[target]

if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum4([1,2,3], 4))