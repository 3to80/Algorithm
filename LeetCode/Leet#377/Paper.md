####Problem
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

#####Note

- 모든 수는 양수, 중복이 업음. 
- 특정 target이 주어졌을 때, input 값들을 이용해 target을 만드는 모든 가지수를 찾아라. 
    - input의 각 값은 여러번 사용할 수 있따. 
    - input의 값 중 일부만 사용할 수 있다. 
    - (1, 1, 2) (1, 2, 1) (2, 1, 1) 처럼 순서가 다른 거도 다른 case라고 생각한ㄷ. 
- follow up : 각 수가 음수일 때 문제를 어떻게 바꿔야 되는가 ? 그리고  어떤 조건을 붙일 ㅜ 있는가 
    
- - -
####Solution
 
- DP 이용

정렬된 input에 대해, 

find(target, input)
- f(target) 
    - rough dp :  {f(target -input`0` )  * f(input`0`)} + {f(target -input`1` )  * f(input`1`)} + {f(target -input`2` )  * f(input`2`)}...
    + {f(target -input`n-1` )  * f(input`n-1`)}
    _- final dp : Sigma(f(target -input`i` )  * f(input`i`)) <- 여기 틀림, *이 아니라 1이 되는거지 .._ 
    **- final dp : Sigma(f(target -input`i` ))** 

        - default : 0
        **- f(0) = 1 and f(input`i`) = 1**
        - 0 계산을 줄이려면 target - input'i' 의 값이 input'0'보다 작다면 그 이후의 값들은 바로 연산을 안해도 된다. 
 
- Exception 발생경우
    - input이 null
    - target이 너무 작을 떄
    _- target이 너무 클 떄 <- 작은 경우, 작은것들을 다 더해서 값은 계속 만드니 이 경우는 exception이 아니다 _ 
- target의 범위에 따라 사용할 input의 범위를 정해야 된다. 
    input`i` < target인 최대 i를 찾는다. <- input`max`
    [input`i`, input'max`] 에 대해 dp를 돌린다.  
   

- - - 
####Analysis
Time complexity

dp(t) 를 구하는데, range(min(Input), max(Input)+1) 만큼을 본다. 그러므로 하나의 값에 최대 O(n)이고 target 까지기 떄문에 
O(n * target)이 된다. 

Space complexity

dp를 만드는데 : O(target).. 최대한 줄이면 O(target - min(Input))

- - -
####Discussion
- - -
####Reference