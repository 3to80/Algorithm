


class Solution:

    def onlyAlphabet(self, s):
        start = s[0]
        for i in s:
            if i != start:
                return False
        return True

    def makePalindrome(self, half):
        ret = str()
        for i in range(len(half)-1):
            ret += half[len(half)-1 - i]
        ret += half
        return ret

    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return str()
        if self.onlyAlphabet(s):
            return s


        min_length = float('inf')
        ret = str()

        for i in range(len(s)):
            prefix = s[:i]
            post = s[i+1:]
            palindrome = self.makePalindrome(s[i:])
            mid = (int)(len(palindrome)/2)
            print(palindrome, " " , palindrome[mid - len(prefix): mid], " ",  post, " " , prefix)
            if palindrome[mid - len(prefix): mid] == prefix:
                ret = min_length > len(palindrome) and palindrome or ret

        return ret





if __name__ == '__main__':
    s = Solution()
    t = "aaacecaaa"

    print(s.shortestPalindrome(t))