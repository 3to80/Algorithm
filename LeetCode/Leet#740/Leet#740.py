class Solution:
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # python에서 10002개의 0으로 초기화된 배열 쉽게 만드는 방법
        # list의 축약형으로
        #  points = [0] * 10001 이런 식으로도 선언 가능
        hashTable = [0 for _ in range(10002)]
        for num in nums:
            hashTable[num] += 1 ## python은 ++ 없나
        # hashTable에 대한 DP를 해보자
        # f(min, max+1) 까지, 이 경우는 [min, max)임

        if not nums :
            return 0

        c, p = 0, 0
        for i in range(min(nums), max(nums)+1):
            c, p = max(p + i * hashTable[i], c), c

        return c


if __name__ == '__main__':
    s = Solution()

    print(s.deleteAndEarn([100,100]))


