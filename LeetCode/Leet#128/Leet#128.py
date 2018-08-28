class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #### 내가 직접 해시 만들어서 (dp 지금 만드는거) 하는 방법은 Memory error가 난다.
        #### 그래서 자체 내장 해시를 사용하자.
        nums = {x - min(nums) for x in nums}
        max_val = max(nums)
        dp = [0] * (max_val+1)
        for i in nums:
            dp[i] += 1
        max_len = -1

        # aux를 다돌릴 때
        tmp = 0
        for i in range(0, max_val+1):
            if dp[i] != 0:
                tmp += 1
            if tmp != 0 and dp[i] == 0:
                if max_len < tmp:
                    max_len = tmp
                tmp = 0

        return max_len

    def longestConsecutive_solution(self, nums):
        nums = set(nums)
        # set(nums) 도 내장 해시를 사용하면 O(n)으로 할 수 있음.
        # 내장 해시 사용하면 맴버십 테스트도 O(1) , 굳이 원시적으로 배열 만들어서 하지 말자 ~
        best = 0
        for x in nums:
            if x - 1 not in nums:
                y = x + 1
                while y in nums:
                    y += 1
                best = max(best, y - x)
        return best


if __name__ == '__main__':
    s = Solution()
    print(s.longestConsecutive_solution([100, 4, 200, 1, 3, 2]))