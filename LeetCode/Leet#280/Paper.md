####Problem

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
#####Note

- - -
####Solution
for i in nums:
    i가 2의배수인지, 아닌지에 따라 
    i와 i + 1 값을 비교

- - - 
####Analysis
Time complexity

O(n)

Space complexity

O(1)
- - -
####Discussion
- - -
####Reference