# Given a non-empty array of integers, every element appears twice except for one. Find that single one.
#
# Note:
#
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memo ry?
# O(n),

# ELement: a1_1, a1_2, a2_1, a2_2 .... , an_1, an_2  // ap 만이 혼자 있다고 하자

# Sum = 2 * sum(a1_1 ~ an_1) - ap

# 메모리 사용하는 경우
# hash



class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        for i in nums:
            ret ^= i

        return ret

if __name__ == '__main__':
    s = Solution()
    print(s.singleNumber([1,1,2,2,3,3,4,4,5]))