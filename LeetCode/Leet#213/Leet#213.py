



class Solution:

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: inty
        """
        if len(nums) < 2:
            return sum(nums)
        #case 1 : skip 1st home
        # dp1 =[0, 0]
        c, p = 0,0
        for num in nums[1:]:
            c, p = max(p+num, c), c
            # dp1.append( max (dp1[-2] + num, dp1[-1]))
        # case 2 : skip last home
        # dp2 = [0, 0]
        c1, p1 = 0,0
        for num in nums[:-1]:
            c1, p1 = max(p1+num, c1), c1
            # dp2.append(max(dp2[-2] + num, dp2[-1]))
        return max(c1, c)
        # return max(dp1[-1], dp2[-1])



if __name__ == '__main__':
    s = Solution()
    print(s.rob([2,3,2]))

