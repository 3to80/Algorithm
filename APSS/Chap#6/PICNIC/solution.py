import fileinput

from copy import deepcopy

def toInteger(s):
    return (int)(s)


def find_smallest(table):
    ret = -1
    for idx, v in enumerate(table):
        if not v:
            return idx
    return ret


def func(table, checkTable):

    firstOne = find_smallest(checkTable)
    if firstOne == -1:
        return 1

    ret = 0
    for i in range(firstOne + 1, V):
        if not checkTable[i] and table[i][firstOne]:
            checkTable[firstOne] = checkTable[i] = True
            ret += func(table, checkTable)
            checkTable[firstOne] = checkTable[i] = False


    return ret


def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])

if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            V = toInteger(t[0])
            E = toInteger(t[1])
            e_info = f.readline().split()

            edgeMap = [[0 for row in range(V)] for col in range(V)]
            # print(e_info)

            for i in range(E):
                s1 = toInteger(e_info[2*i])
                s2 = toInteger(e_info[2*i+1])
                # print(s1, s2)
                edgeMap[s1][s2] = 1
                edgeMap[s2][s1] = 1

            # print_2dim(edgeMap)
            picked = []
            ret = 0
            checkTable = [False for i in range(V)]
            ret = func(edgeMap, checkTable)
            print(ret)
