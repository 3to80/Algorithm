import collections

# Definition for a point.# Definition for a poin
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        if not points:
            return 0
        res = 1
        for i in range(len(points)):
            same_cnt = 1
            d = collections.defaultdict(int)
            x0, y0 = points[i].x, points[i].y
            for j in range(i):
                ## 한 점에서, 이 점과 다른 점의 관계들을 생각 ( 3가지, 동일, 수직, 기울기) + DP 느낌도 나네
                x, y = points[j].x, points[j].y
                if x == x0 and y == y0:
                    same_cnt += 1
                elif x == x0:
                    d['v'] += 1
                else:
                    d[(y - y0) * 1.0 / (x - x0)] += 1
            if d:
                same_cnt += max(d.values())
            res = max(res, same_cnt)
        return res