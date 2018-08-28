import fileinput


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
            vertices = list(range(num_vertices))
            vertexMap = [True for x in range(num_vertices)]


            def traverse(start, remainder):
                tmp = [rem for rem in remainder if vertexMap[rem]]
                if len(tmp) == 1:
                    return edgeTable[start][tmp[0]]

                cand = list()
                for next in [rem for rem in remainder if vertexMap[rem]]:
                    vertexMap[next] = False
                    cand.append(edgeTable[start][next] + traverse(next, remainder))
                    vertexMap[next] = True

                return min(cand)

            def shortest(vertices):
                if len(vertices) < 2:
                    return -1
                cand = list()
                for start in vertices:
                    vertexMap[start] = False
                    cand.append(traverse(start, vertices))
                    vertexMap[start] = True
                return min(cand)

            print(shortest(vertices))


# import sys
# rl = lambda: sys.stdin.readline()
# n = int(rl())
# for i in range(n):
#   print "Hello, %s!" % rl().strip()