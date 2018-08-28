import math


class Solution(object):
    def distance(self, i, j):
        pass

    def shortestPathLength(self, graph):
        nodeNum = len(graph)
        #INIT
        DP = [[float('inf')] * nodeNum for x in range(pow(2, nodeNum))]
        i = 0
        for g in graph:
            DP[1<<i][i] = 0
            i += 1

        #LOOP
        for bitMap in range(pow(2, nodeNum)):
            for node in range(nodeNum):
                # make prev_bitmap_list
                minv = float('inf')
                for i in range(len(graph)):
                    tmp = bitMap ^ (1 << i)
                    if tmp < bitMap:
                        minv= min(minv, DP[tmp][i] + self.distance(i, node))
        #FINAL

        return min(DP[pow(2, nodeNum)-1])