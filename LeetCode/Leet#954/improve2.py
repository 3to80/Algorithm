class Solution:
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        Time : O(nlgn)
        Space : O(n) because of dict
        """
        dictA = collections.Counter(A)
        
        for x in sorted(dictA, key= lambda x: abs(x)):
            if dictA[x] > dictA[2*x]: return False
            dictA[2*x] -= dictA[x]
            
        return True
                
