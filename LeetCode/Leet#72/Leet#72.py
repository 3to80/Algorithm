import itertools


class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        E1 = [[0] * len(word1)] * len(word2)
        E1[0][0] = 2
        E2 = [[0] * len(word1) for i in range(len(word2))]
        print(E1, E1[0] == E1[1])
        E2[0][0] = 2

        print(E2, E2[0] == E2[1])


if __name__ == '__main__':
    s = Solution()
    s.minDistance('qwer', 'ef')
