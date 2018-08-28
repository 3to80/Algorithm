import itertools
import math




class Solution:
    def makeLine(self, p1, p2):
        p, q, r, s = p1[0], p1[1], p2[0], p2[1]
        if p != r:
            # s-q 랑 r -p 부호가 같다면 ,, q*r-p*s랑 r-p 부호가 같다면
            tmp =  [int((s - q) / math.gcd(s - q, r - p)), int((r - p) / math.gcd(s - q, r - p)),
                int((q * r - p * s) / math.gcd((q * r - p * s), r - p)),
                int((r - p) / math.gcd((q * r - p * s), r - p))
                ]
            ## 분모는 항상 양수가 되게
            if tmp[1] < 0:
                tmp[1] *= -1
                tmp[0] *= -1
            if tmp[3] < 0:
                tmp[3] *= -1
                tmp[2] *= -1
            return tuple(tmp)

        else:
            return (r, 0, 0, 0)

    def get_FinalNum(self, num):
        return (int)((math.sqrt(num * 8 + 1) - 1) / 2)

    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        # 점들의 중복을 없앤 list : ([x, y], 개수 )
        aux_Nodup = {}
        for point in points:
            if not aux_Nodup.get((point.x, point.y)):
                aux_Nodup[(point.x, point.y)] = 1
            else:
                aux_Nodup[(point.x, point.y)] += 1

        if not aux_Nodup:
            return 0
        if len(aux_Nodup) == 1:
            for i in aux_Nodup.keys():
                return aux_Nodup.get(i)

        aux_line = {}
        for p1, p2 in itertools.combinations(aux_Nodup.keys(), 2):
            target = self.makeLine(p1, p2)
            if not aux_line.get(target):
                aux_line[target] = (aux_Nodup.get(p1) + aux_Nodup.get(p2), 1)
            else:
                aux_line[target] = (aux_line[target][0] + aux_Nodup.get(p1) + aux_Nodup.get(p2), aux_line[target][1]+1)

        max_val = -1
        for itm in aux_line.values():
            tmp = (int)(itm[0] / self.get_FinalNum(itm[1]))
            max_val = tmp > max_val and tmp or max_val

        return max_val

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def getPoint(args):
    ret = []
    for i in args:
        ret.append(Point(i[0], i[1]))
    return ret

if __name__ == '__main__':
    s = Solution()
    a = getPoint([[3,3],[1,1],[2,2]])
    print(s.maxPoints(a))



