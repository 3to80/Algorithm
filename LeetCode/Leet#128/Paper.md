####Problem
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


#####Note

- 정렬되어 있지 않은 정수들 (음 , 0, 양 )
- 가장 긴,  연속 수들로 이루어진 개수 찾기
    - 연속 뿐 수열이 아님
    - 연속되는 수들의 집합에서 가장 큰거고, 이거는 그냥 임의의 피을 하면 된다 
- O(n)


- - -
####Solution


aux <- O(max(Input))

Input <- Input + min(Input) : 모든 값들을 0이상의 정수로 만들어서 더함. 

Input iteration을 하며, Input을 aux에 기록한다. 

aux와 Input에서, 
    - aux[Input`i`]에 대해 몇개나 연속적인지를 찾는다. 
    - 찾으면 찾은 애를 지워 나가면서 INput의 수를 줄여 나가는건 개애배ㅏ 
aux를 돌며 연속적인 곳들을 찾는다. 
    - O(max(Input))이 된다. 
        - max(Input)은 너무 불안 요소 
=> 실제로 Memomry error 남

해결 -> 내장 해시 사용


- - - 

####Analysis
Time complexity

start 될 수 있는 곳들 찾는데 O(n)
+ 
O(n) -> k개의 시작점 

각 시작점에 대해서, 

k1 ->  d1  -> O(d1)
k2 ->  d2  -> O(d2)
ki ->  dk  -> O(dk)


O(d1 + d2 + d3 ... + dk) <= O(n)

[5, 4, 3, 2, 1 , 
10, 11, 12, 13, 
46,47, 
55]


-> O(n) + O(d1) + O(d2) + ...  < = O(n)

Therefore, O(n)





Space complexity

O(n)




- - -
####Discussion

배열 만들지 말고 내장 해시를 자주 사용하기
 - 해시 구현 

- - -
####Reference

- - -





