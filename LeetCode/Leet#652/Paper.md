####Problem


#####Note

- - -
####Solution
  
My solution

- 
-

Leet solution

class Solution(object):
    
    
    def findDuplicateSubtrees(self, root):
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__

        count = collections.Counter()
        ans = []
        
        def lookup(node):
            if node:
                uid = trees[(node.val, lookup(node.left), lookup(node.right))]
                count[uid] += 1
                if count[uid] == 2:
                    ans.append(node)
                return uid
        lookup(root)

        return ans



- 상당히 pythonic 하게 잘 짜인 코드 같음, defaultdict 도 잘 쓴거도 있지만 재귀도 쩌네.. 


- - - 
####Analysis
My solution

- Time complexity
O(n^2)
- Space complexity
O(n^2)

Leet solution

- Time complexity
O(n)

- Space complexity
O(n)


- - -
####Discussion

 - Tree에서 재귀 타기
 - dict의 key로 쓸 수 있는건 hashable and  immutable 
    -> set은 key로 쓸 수 없지만 frozen set은 키로 쓸 수 있따.
    -> tuple도 key로 사용 가능 
    

- - -
####Reference