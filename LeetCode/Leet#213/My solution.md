####Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#####Note

Input : [2, 3, 2] 
Output: 3

- Input의 각 element는 각 집의 재산 상태, 집은 총 2개가 있는 거
- 3인 집만 갈 수 있으니 3만

Input : [1,2,3,1]
Output : 4
- 집은 총 4채 
- 1 3

- - -
####Solution
 
각 집의 위치는 list의 index가 됨. 

path <-[]
sum <- path의 집의 돈들의 합 

문제의 조건을 만족하는 path가 [a`0`, a`1`, a`2`, a`3`... a`n-1`]라고 하자.  
이때 |a`i` - a`i+1`| > 1 and |a`i` - a`i+1`| != n-1 을 만족해야 하고  
sum이 최대인 집을 찾아야 한다. 


모든 값이 non-integer이기 때문에 , 가급적 많을수록 좋다.(종종 아닌 경우가 있음)

작은 case부터 생각

Input : [1,2,3,1,5] end 

h(start, end) : arr[start: end) 가지의 최대금액 

h(0, len(nums))

<= max( 
    h1(2, len(arr)-1) + arr[0],
    h1(1, len(arr)-2) + arr[-1],
)

첫 원소를 선택하는 경우



h1(2, len(arr)-1) + arr[0]

첫 원소를 선택하지 않는 경우

h1(1, len(arr)-2) + arr[-1]


h1(n) = max(h1(n-2) + arr[n] , h1(n-1))
      
      
- - - 
####Analysis
Time complexity
O(n)
Space complexity
O(n) -> O(1) 
 매 순간 필요한 dp를 하는데 필요한 변수는 O(1)개 
- - -
####Discussion
- - -
####Reference