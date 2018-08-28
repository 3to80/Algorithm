import fileinput
from collections import deque, defaultdict
import copy


def toInteger(s):
    return (int)(s)

def toFloat(s):
    return float(s)

def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])


NUM = 16

if __name__ == '__main__':

    switches = [
        [0,1,2],
        [3,7,9,11],
        [4,10,14,15],
        [0,4,5,6,7],
        [6,7,8,10,12],
        [0,2,14,15],
        [3,14,15],
        [4,5,7,14,15],
        [1,2,3,4,5],
        [3,4,5,9,13]
    ]

    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            clocks = [(toInteger(s)/3) % 4 for s in t]

            queue = deque()

            def update(clocks, switch):
                clocks_cpy = copy.deepcopy(clocks)
                for i in switch:
                    clocks_cpy[i] += 1
                    clocks_cpy[i] %= 4
                return clocks_cpy

            def is_end(clocks):
                for i in clocks:
                    if i:
                        return False
                return True

            def encoding(clocks, seed):
                ret = 0
                for idx, val in enumerate(clocks):
                    ret += pow(val, idx)
                return ret

            dict = defaultdict()

            for switch in switches:
                queue.appendleft([update(clocks, switch), 1])


            seed = 5
            ret = -1
            while queue:
                target = queue.pop()
                tmp = encoding(target[0], seed)

                if not dict.get(tmp):
                    dict[tmp] = 1
                else:
                    continue

                if is_end(target[0]):
                    ret = target[1]
                    break

                # if, target[0]이 한 번 나온 값이라면, pop한 상태에서 없애는 거
                for switch in switches:
                    queue.appendleft([update(target[0], switch), target[1] + 1])

            print(ret)
