####Problem
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
#####Note
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
- - -
####Solution
Element 다 돌며 xor 시키기  
 - xor는 교환, 결합 법칙 성립
 - xor의 역원은 자기 자신
 

- - - 
####Analysis
Time complexity
 - iteration : O(n)
 - 임의의 두 수에 대한 xor 계산을 O(1)이라 가정

=> O(n) 

Space complexity

=> O(1)
- - -
####Discussion
- - -
####Reference