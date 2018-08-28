# Define f(element, level).


# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger(object):
#    def __init__(self, value=None):
#
#    def isInteger(self):
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """



# f(element, level):
#     #Exception
#     if not element:
#         return 0
#     #Default
#     if element is singleIntger:
#         return element * level
#     #Recursion
#     ret = 0
#     for i in element:
#         ret +=f(i, level+1)
#     return ret


# [[1,1],2,[1,1]]
# [Nested, Nested, Nested]
# [[],[]],[]]

class Solution(object):
    def f(self, element, level):
        # Exception
        # Default
        if not isinstance(element, list):
            if not element.isInteger():
                return 0
            return element.getInteger() * level

        # Recursion

        ret = 0
        for i in element:
            if i.getList():
                ret += self.f(i.getList(), level + 1)
            else:
                ret += self.f(i, level + 1)
        return ret

    def depthSum(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        return self.f(nestedList, 0)