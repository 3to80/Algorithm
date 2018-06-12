class Solution:
    def minSubArrayLen(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        #float('inf') 이런 식으로 무한 표현
        _min = float('inf')
        _sum = 0
        j = 0

        # python에서 for 는 iterable 을 이용해서 돌리니까 idx 잡는게 힘들잖아. 그래서 enumerate를 써서 사용할 수 있겠네
        for i ,n in enumerate(nums):
            _sum += n
            while _sum>=k:
                _min = min(i-j+1, _min)
                _sum -= nums[j]
                j+=1
        return _min if _min!=float('inf') else 0
