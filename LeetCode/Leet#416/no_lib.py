class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        S = sum(nums)
        
        if S %2 == 1: return False
        
        T = S/2
        
        # simple Counter 생성
        # 201 size  array 생성
        aux = [ 0 for x in range(201)]
        for i in nums:
            aux[i] += 1
        
        
        def func(T, nums, aux):
            """
            @Input :
                T : Integers
                nums : duplicate list, 
            @Output : boolean value which indicates whether sum of the subset is T-value  
            
            @Logic :                
                @Recursion : 
                    Steps: T, nums
                    1) T == 0 : 
                        return True
                    2) T < 0 :
                        RETURN;
                    3) T > 0:
                        (1) pick some value 
                        (2) update Data structure
                        (3) next := func(T-pickVal, nums, cnter)
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
                # Counter >0 인 것 중에 T보다 작으면서 가장 큰  K, V 를 찾는다. 
                # update Counter and recursion next step
                
                for k, v in enumerate(aux):
                    if aux[k] < 1 or k > T: continue
                    aux[k] -= 1
                    next_ret = func(T - k, nums, aux)
                    if next_ret: return True
                    aux[k] += 1
                
                return False
                
            

        return func(T, nums, aux)
        
