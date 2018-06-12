class Solution:

    NO_ANSWER = 99999

    def find_greater_least_idx_iter(self, li, start, end, target):
        if end - start <= 0:
            return self.NO_ANSWER
        else:
            mid = start + (int)((end - start)/2)
            if li[mid] == target:
                return mid
            elif li[mid] > target:
                if mid-1 >= 0 and li[mid-1] < target:
                    return mid
                return self.find_greater_least_idx_iter(li, start, mid, target)
            else:
                if mid+1 < len(li) and li[mid+1] > target:
                    return mid + 1
                return self.find_greater_least_idx_iter(li, mid+1, end, target)

    def find_greater_least_idx_binary(self, subSum, target):
        return self.find_greater_least_idx_iter(subSum, 0, len(subSum), target)

    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        min_v = self.NO_ANSWER

        subSum = [0]
        for i in nums:
            subSum.append(subSum[-1]+i)

        for s_idx in range(len(nums)):
            e_idx = self.find_greater_least_idx_binary(subSum, s + subSum[s_idx])
            if e_idx != self.NO_ANSWER:
                min_v = min(e_idx - s_idx, min_v)

        if min_v == self.NO_ANSWER:
            return 0
        return min_v



if __name__ == '__main__':

    s = Solution()
    print(s.find_greater_least_idx_binary([2,4,6,8,10], 5))
    print(s.minSubArrayLen(11, [1,2,3,4,5]))