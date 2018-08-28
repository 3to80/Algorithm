import fileinput
import copy


def toInteger(s):
    return (int)(s)

def toFloat(s):
    return float(s)

def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])



def update(clocks, switch):
    clocks_cpy = copy.deepcopy(clocks)
    for i in switch:
        clocks_cpy[i] += 1
        clocks_cpy[i] %= 4
    return clocks_cpy




def update2(clocks, switch):
    for i in switch:
        clocks[i] += 1
        clocks[i] %= 4


def recover2(clocks, switch):
    for i in switch:
        clocks[i] -= 1
        clocks[i] %= 4


def is_all_zero(clocks):
    for i in clocks:
        if i:
            return False
    return True


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
            limits = [3 for x in range(10)]



            def solve(clocks, switch):
                if switch == 10:
                    if is_all_zero(clocks):
                        return 0
                    else :
                        return float('inf')

                minVal = float('inf')

                for num in range(4):
                    minVal = min(minVal, num + solve(clocks, switch+1))
                    update2(clocks, switches[switch])
                return minVal

            ret = solve(clocks, 0)

            if ret == float('inf'):
                ret = -1
            print(ret)

        #     SWITCH = 10
        #
        #     for idx, switch in enumerate(switches):
        #         if not limits[idx]: ### 3개씩 쓰는걸 강제 해버림 .
        #             continue
        #         limits[idx] -= 1
        #         update2(clocks, switch)
        #         tmp = solve(limits, switches, clocks)
        #         if tmp != float('inf'):
        #             minVal = min(minVal, tmp + 1)
        #         limits[idx] += 1
        #         recover2(clocks, switch)
        #
        #     return minVal
        #
        # ret = solve(limits, switches, clocks)
