"""
Time Complexity : O(N)
Space Complexity : O(N)

# f(arr, i, rem):
#     a := [0, i) 최대 값 
#     b := [i, end)의 최소
#     if a < b:
#         f(arr, i+1, rem+1)    
#     else:
#         return f(arr, i+1, rem)
#           [1, 3, 3, 3, 3, 3, 1, 4]
# beforeMax [1, 3, 3, 3, 3, 3, 3, 4]
# afterMin  [1, 1, 1, 1, 1, 1, 1, 4]

"""

class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if len(arr) <= 1:
            return 1
        
        # [0, i)까지의 최대 값을 저장
        beforeMax = [arr[0]]
        # 1 3 3 3 3 
        for i in range(1, len(arr)):
            tmp = beforeMax[-1]
            if arr[i] > tmp:
                beforeMax.append(arr[i])
            else:
                beforeMax.append(tmp)
        # [i, end) 까지에서 최소 값
        # 1 3 3 3 3 3 1 4

        afterMin = [arr[x] for x in range(len(arr))] 
        for i in range(len(arr)-2, -1, -1):
            tmp = arr[i]
            if tmp < afterMin[i+1]:
                afterMin[i] = tmp
            else:
                afterMin[i] = afterMin[i+1]
            
        def f(arr, i, rem):
            if i == len(arr):
                return rem            
            a = beforeMax[i-1]
            b = afterMin[i]
            if a <= b:
                return f(arr, i+1, rem+1)
            else:
                return f(arr, i+1, rem)
            
        return f(arr, 1, 1)
    
            
            
            
    
