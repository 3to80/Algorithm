import fileinput
from collections import defaultdict

def toInteger(s):
    return (int)(s)

def toFloat(s):
    return float(s)

def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])


if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            num_vertices = toInteger(t[0])
            edgeTable = [0 for row in range(num_vertices)]
            for row in range(num_vertices):
                tmp = f.readline().split()
                edgeTable[row] = [toFloat(itm) for itm in tmp]

            print_2dim(edgeTable)
            vertices = set(range(num_vertices))
            aux = defaultdict(lambda: 0)

            def traverse(start, remainder):
                """

                :param start: Int
                :param remainder: Set{Integer}
                :return: Integer
                """
                if len(remainder) == 1:
                    return edgeTable[start][remainder.pop()]

                cand = list()
                for next in remainder:
                    tmp = edgeTable[start][next] + traverse(next, remainder.difference({next}))
                    cand.append(tmp)
                return min(cand)

            def shortest(vertices):
                """
                :param vertices: set[Integer]
                :return: Int
                """
                if len(vertices) < 2:
                    return -1
                cand = list()
                for start in vertices:
                    cand.append(traverse(start, vertices.difference({start})))
                return min(cand)

            print(shortest(vertices))


# import sys
# rl = lambda: sys.stdin.readline()
# n = int(rl())
# for i in range(n):
#   print "Hello, %s!" % rl().strip()