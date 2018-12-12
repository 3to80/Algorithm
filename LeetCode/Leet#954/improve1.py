"""
Imporvement 1. 

More pythonic
- improvement1
    - using sort(key = lambda x: (x>0, abs(x)))
- imporvement2
    - time complexity : O(nlgn), space complexity : O(1)
"""

    
class Solution:
    

    
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        # 앞부분은 음수들에 대해 절대값 정렬, 끝나면 뒤쪽으로 양수들에 대해 절대값 정렬 . 
        # (false, abs(-10)) (true, abs(10)) 이런 식, 앞에 bool이 먼저 정렬된다 
        A.sort(key= lambda x: (x>0, abs(x)))
        pos, pos2, checked = 0, 0, 100001           
        while pos < len(A):
            # 2*aux[pos] == aux[pos2]인 pos2를 찾는다. 
            if A[pos] == checked:
                pos += 1
                continue
            try: pos2 = A.index(A[pos] * 2, pos2)
            except ValueError: return False
            A[pos2] = checked
            pos+=1
        return True

        
