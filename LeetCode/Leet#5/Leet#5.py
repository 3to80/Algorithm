import itertools


class Solution:
    def solve(self, s, dp, i, j):

        if j == i + 1:
            dp[i][j] = (int)(s[i] == s[j])
        else:
            if s[i] == s[j]:
                if dp[i + 1][j - 1] == -1:
                    self.solve(s, dp, i + 1, j - 1)
                dp[i][j] = dp[i + 1][j - 1]

            else:
                dp[i][j] = 0




    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: st
        """
        # dp[i][j] " s[i:j+1] 가 palindrome이면 True, 아니면 False , i <= j < len(s)

        if len(s) == 1:
            return s
        dp = [[-1] * (len(s)) for x in range(len(s))]

        # for i in range(len(dp)):
        #     dp[i][i] = 1
        print(s)
        for i in range(len(s) - 1):
            dp[i][i] = 1
            dp[i][i + 1] = (int)(s[i] == s[i + 1])

        dp[len(s) - 1][len(s) - 1] = 1

        for i in range(len(dp)):
            print(dp[i])


        for i, j in itertools.combinations(range(len(s)), 2):
            self.solve(s, dp, i, j)

        for i in range(len(dp)):
            print(dp[i])

        max_string = str()
        for i in range(0, len(s)):
            for j in range(i, len(s)):
                if dp[i][j] == 1:
                    max_string = len(max_string) < (j + 1 - i) and s[i:j + 1] or max_string

        return max_string


if __name__ == '__main__':
    s1 = Solution()
    t = "abbba"
    print(s1.longestPalindrome(t))








