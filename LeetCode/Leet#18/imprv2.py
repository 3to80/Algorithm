"""
Sorting + Recursion + Heuristic
Time Complexity:

N 4

Time complexity: O(N^2) * ..  
2개 남은 경우, 
[left, right]
1/n( kn + k(n-1) + k(n-2)... k 1) -> O(n)
--> O(N^3)
Therefre, O(N^3)
Space complexity : O(1)

"""
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        
        def func(level, left, right, nums, target, tmp, ret):
            # filter case using heuristic count, min and max 
            if right-left+1 < level or target < level * nums[left] or target > level * nums[right]: return
            
            if level == 2: # 2개를 선택해야 하는 경우
                while left < right:
                    s = nums[left] + nums[right]
                    if s == target:
                        # 4개가 딱 맞게 골라진 경우
                        ret.append(tmp + [nums[left], nums[right]])
                        left += 1
                        # 앞에서 중복되는 부분 제거 
                        while left < right and nums[left] == nums[left-1]: left += 1
                    elif s < target: left += 1
                    else: right -= 1

            else:
                for i in range(left, right+1):
                    if i == left or (i > left and nums[i-1] != nums[i]) : # 처음에 pick 는 수는 항상 다른 숫자만 되게. 
                        func(level-1, i+1, right, nums, target-nums[i], tmp + [nums[i]], ret)
                    
            
                
        ret = []
        func(4, 0, len(nums)-1, nums, target, [], ret)
        
        return ret
        
        
        
        


