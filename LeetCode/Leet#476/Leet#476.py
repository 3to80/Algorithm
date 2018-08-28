# Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
#
# Note:
# The given integer is guaranteed to fit within the range of a 32-bit signed integer.
# You could assume no leading zero bit in the integer’s binary representation.
# 5  : 101 -> 010, 2
# 1 : 1  -> 0, 0

import math


class Solution:

    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        # 16 -> 4 31-> 4.xxx
        # 4 -> 2 , 필요한 자리 수는 3자리
        need_digit = math.trunc(math.log2(num))+1
        helper = pow(2, need_digit)-1
        return num ^ helper


if __name__ == '__main__':


    s = Solution()
    for i in range(1, 10):
        print(s.findComplement(i))
