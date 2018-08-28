# Write a function that takes a string as input and returns the string reversed.
#
# Example:
# Given s = "hello", return "olleh".


#java의 STRING BUILDER같은게 있을 까
class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Brute
        stack = ""
        # stack= stack
        for i in range(0, len(s)):
            stack += s[-1-i]
            # stack.append(s[-1-i])


        return stack


if __name__ == '__main__':
    s = Solution()
    print(s.reverseString("qwer"))