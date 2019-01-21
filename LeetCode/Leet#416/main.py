from collections import Counter

class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        S = sum(nums)
        
        if S %2 == 1: return False
        
        T = S/2
        
        cnter = Counter(nums)
        
        
        def func(T, nums, cnter):
            """
            @Input :
                T : Integers
                nums : duplicate list, 
            @Output : boolean value which indicates whether sum of the subset is T-value  
            
            @Logic :
                Brute Force + Efficeint Search
                
                @Recursion : 
                    Steps: T, nums
                    1) T == 0 : 
                        return True
                    2) T < 0 :
                        RETURN;
                    3) T > 0:
                        (1) pick some value 
                        (2) update Data structure
                        (3) next := func(T-pickVal, nums, picked)
                        (4) update Data structure
                        * 개선 point 
                            - Counter를 만들고, binary Search 를 하는 방향으로 생각할 수 있음.
                            - Array Value < 100 and Array Size < 200 
            """            
            if T == 0:
                return True
            elif T < 0:
                return False
            else:
                
                """ 
                * Brute force algo *
                for i in range(len(picked)):
                    if picked[i]:continue
                    # 안골라진 거에 대해 하나를 선택한다. 
                    picked[i] = True
                    next_ret = func(T - nums[i], nums, picked)
                    if next_ret :
                        return True
                    picked[i] = False                    
                return False
                """
                # Counter >0 인 것 중에 T보다 작으면서 가장 큰  K, V 를 찾는다. 
                # update Counter and recursion next step
                
                for k, v in cnter.items():
                    if cnter[k] < 1 or k > T: continue
                    cnter[k] -= 1
                    next_ret = func(T - k, nums, cnter)
                    if next_ret: return True
                    cnter[k] += 1
                
                return False
                
            

        return func(T, nums, cnter)
        
        
