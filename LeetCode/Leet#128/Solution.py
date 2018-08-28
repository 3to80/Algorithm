def longestConsecutive_solution(self, nums):
    nums = set(nums)
    # set(nums) 도 내장 해시를 사용하면 O(n)으로 할 수 있음.
    # 내장 해시 사용하면 맴버십 테스트도 O(1) , 굳이 원시적으로 배열 만들어서 하지 말자 ~
    best = 0
    for x in nums:
        if x - 1 not in nums:
            y = x + 1
            while y in nums:
                y += 1
            best = max(best, y - x)
    return best