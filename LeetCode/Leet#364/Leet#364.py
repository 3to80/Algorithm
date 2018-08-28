# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
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

class Solution(object):


    def get_max_depth(self, nestedList):
        """
        :param nestedList: List[NestedInteger
        :return: int
        """
        ret = 1

        while nestedList:
            # x 에서, x.isINteger() 를 만족하는 x 들에 대해, x.getList()를 []에 넣는다.
            nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], [])
            ret += 1

        return ret

    def get_depth_sum_inv(self, nestedList, max_depth):
        """

        :param nestedList:
        :param max_depth:
        :return: int
        """

        ret = 0
        depth = 1
        while nestedList:
            ret += sum([x.getInteger() for x in nestedList if x.isInteger()]) * (max_depth - depth)
            nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], [])
            depth += 1

        return ret




    def depthSumInverse(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        # 1. find max Depth in nested List
        # 2. using DFS with max depth in step 1, calculate inverse level sum
        return self.get_depth_sum_inv(nestedList, self.get_max_depth(nestedList))


















