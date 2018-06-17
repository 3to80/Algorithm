import math

class Solution:
    def checkInt(self, target):
        if target - int(target) == 0:
            return True
        else:
            return False
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """

        ret = 0
        max_i = (int)((math.sqrt(1+ 8 * N)-1)/2)
        for i in range(1, max_i+1):
            target = (N- i*(i-1)/2)/i
            if self.checkInt(target):
                ret += 1
        return ret


if __name__ == '__main__':
    s = Solution()
    print(s.consecutiveNumbersSum(15))