class Solution:
    NO_ANSWER = 99999
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        for i, n in enumerate(nums):
            print(i, n)
        if not nums or sum(nums) < s:
            return 0

        min_val = self.NO_ANSWER
        s_idx, e_idx, ret = 0, 1, nums[0]
        while ret < s:
            ret += nums[e_idx]
            e_idx += 1

        # s_idx, e_idx, e_idx 잡는게 햇갈리면, 이게 어디를 도는지를 먼저  생각해보자
        while ret >= s:
            min_val = min(min_val, e_idx - s_idx)
            ret -= nums[s_idx]
            s_idx += 1
            while e_idx < len(nums) and ret < s:
                ret += nums[e_idx]
                e_idx += 1

        return min_val



if __name__ == '__main__':

    s = Solution()
    print(s.minSubArrayLen(7, [2,3,1,2,4,3]))