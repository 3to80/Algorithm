from itertools import zip_longest
import math
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        # """
        # :type l1: ListNode
        # :type l2: ListNode
        # :rtype: ListNode
        # """

        ret, carry = [], 0
        while l1 or l2:
            a, b = l1 and l1.val or 0, l2.val if l2 else 0

            ret.append((a + b + carry) % 10)
            carry = (int)((a + b + carry) / 10)
            l1, l2 = l1.next if l1 else None, l2.next if l2 else None
        if carry:
            ret.append(carry)


        return ret



if __name__ == '__main__':
    s = Solution()
    print(s.addTwoNumbers([1,2,3],[1,2,3,4,5]))
