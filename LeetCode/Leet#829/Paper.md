

####Problem

Example 1:

Input: 5  
Output: 2  
Explanation: 5 = 5 = 2 + 3  
Example 2:  

Input: 9  
Output: 3  
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4  
Example 3:  

Input: 15  
Output: 4  
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5  
Note: 1 <= N <= 10 ^ 9.  

#####Note

- - -
####Solution
내풀이

    class Solution:


    def checkInt(self, target):
        if target - int(target) == 0:
            return True
        else:
            return False
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        # Solution 3. 계산
            ret = 0
            min_i = (int)((math.sqrt(1+ 8 * N)-1)/2)
    
            for i in range(min_i, N+1):
                target = i * (i + 1) - 2 * N
                if target >= 0:
                    tmp = (math.sqrt(target * 4 + 1) -1)/2
                    if self.checkInt(tmp):
                        ret += 1
    
            return ret

Accept 풀이
    
    class Solution:
        def checkInt(self, target):
            if target - int(target) == 0:
                return True
            else:
                return False
        def consecutiveNumbersSum(self, N):
            """
            :type N: int
            :rtype: int
            """
    
            ret = 0
            max_i = (int)((math.sqrt(1+ 8 * N)-1)/2)
            for i in range(1, max_i+1):
                target = (N- i*(i-1)/2)/i
                if self.checkInt(target):
                    ret += 1
            return ret

- - - 
####Analysis
Time complexity
  - O(N**(1/2))
  
Space complexity
- O(1)

- - -
####Discussion


iteration 할 때, 더 작게 iteration 할 수 있는 지를 더 생각


- - -
####Reference