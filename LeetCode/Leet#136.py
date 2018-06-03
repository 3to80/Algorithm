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



# Approach #4 Bit Manipulation [Accepted]
# Concept
#
# If we take XOR of zero and some bit, it will return that bit
# a \oplus 0 = aa⊕0=a
# If we take XOR of two same bits, it will return 0
# a \oplus a = 0a⊕a=0
# a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b
# So we can XOR all bits together to find the unique number.

class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2*sum(set(nums)) - sum(nums)
