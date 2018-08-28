import heapq



def minMeetingRooms(intervals):
    intervals.sort(key=lambda x:x.start)
    heap = []  # stores the end time of intervals
    for i in intervals:
        if heap and i.start >= heap[0]:
            # means two intervals can use the same room
            heapq.heapreplace(heap, i.end)
        else:
            # a new room is allocated
            heapq.heappush(heap, i.end)
    return len(heap)


import heapq as hq


def minMeetingRooms(self, intervals):
    intervals.sort(lambda x, y: x.start - y.start)
    ans, pq = 0, []
    for interval in intervals:
        while pq and pq[0] <= interval.start:
            hq.heappop(pq)
        hq.heappush(pq, interval.end)
        ans = max(ans, len(pq))
    return ans