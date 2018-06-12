####Problem
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 


#####Note

- - -
####Solution
- 앞부터 차근차근 더해나간다. 처음 s를 넘는 지점에서부터, 앞 idx, 뒤 idx를 적절히 조절해나가며 최단 거리를 구한다.

- - - 
####Analysis
1) O(n) 방법

- Time complexity : O(n)


- Space complexity : O(1)


2) O(nlogn) 방법 
 => 부분합 배열을 만든다. 부분합 배열은 sorted 되있으니 binary search를 이용할 수 있음. 

- Time complexity : O(nlogn)

- Space complexity : O(n), 부분합 배열을 만드는데 필요,



- - -
####Discussion

- Python에서 배열 표현을 enumerate 통해서도 할 수 있음 

<pre><code>
for i, n in enumerate(nums):
    print(i, n)
</code></pre>

- - -
####Reference

