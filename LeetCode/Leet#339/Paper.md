####Problem

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)


#####Note

- - -
####Solution
  
My solution

<pre><code>

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

</pre></code>


Leet solution

<pre><code>
class Solution(object):
    def depthSum(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        depth, ret = 1, 0
        while nestedList:
            ret += depth * sum([x.getInteger() for x in nestedList if x.isInteger()])
            nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], [])
            depth += 1
        return ret
</code>
</pre>

- - - 
####Analysis
My solution

- Time complexity
    : O(each_level * each_item) <= O(max(level) * n)

- Space complexity
    : O(1)

Leet solution

- Time complexity
    : O(each_level * each_item) <= O(max(level) * n)

- Space complexity
    : O(n),  nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], []) 할 때 O(n) 씩 더 만들어야 되기 때문 
           


- - -
####Discussion

- leet solution code 간결하게 잘 짰다. 

            ret += depth * sum([x.getInteger() for x in nestedList if x.isInteger()])
            nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], [])

- 축약형을 더 자주 쓰기 
- - -
####Reference
