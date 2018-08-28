# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
from collections import Counter

class Solution:
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0
        starts, ends = [], []
        for i in intervals:
            starts.append(i.start)
            ends.append(i.end)

        starts.sort()
        ends.sort()
        s = e = 0
        numRooms= avaliable = 0
        while s < len(starts):
            if starts[s] < ends[e]:
                if avaliable == 0:
                    numRooms += 1
                else:
                    avaliable -= 1
                s+=1
            else:
                avaliable += 1
                e += 1

        return numRooms

    def minMeetingRooms1(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0
        max_room, curr_room = 0, 0
        s_ord, e_ord = [], []

        for i in intervals:
            s_ord.append(i.start)
            e_ord.append(i.end)


        min_start, max_end  = min(s_ord), max(e_ord)
        s_set, e_set = Counter(s_ord), Counter(e_ord)

        for curr_time in range(min_start, max_end):
            if curr_time in e_set:
                curr_room -= e_set[curr_time]
            if curr_time in s_set:
                curr_room += s_set[curr_time]
                max_room = max(curr_room, max_room)
        return max_room


# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


if __name__ == '__main__':
    intervals = [Interval(0, 30), Interval(5, 10), Interval(15, 20)]
    s = Solution()
    print(s.minMeetingRooms(intervals))