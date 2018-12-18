"""
Input : N개의 정수 배열


move 규칙
- N개의 item 중에서 N-1개의 item을 선택한다. 그리고 이 item들을 1 increment 한다. 

이러한 Move를 여러 번 통해 모든 element의 값을 동일하게 만든다고 할 때 최소 move 횟수는?

=> 전체 item의 값을 1 더한다. 
=> N개의 item에서 i번째 ( 0<= i < N) 을 1을 뺀다. 즉 1을 뺄 item을 선택해 1을 뺀다.

<-> increment 1을 하고 한개의 1을 빼서 같게 만든다는 거 < == > *하나를 선택해서 1만 감소 시킬 때, 전체가 똑같게 만드는 거 *

Time: O(N)
Space : O(1)



"""


class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums) - len(nums)*min(nums)
        
        
