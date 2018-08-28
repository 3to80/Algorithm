import fileinput


def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])



def getArea(fence_info, start, end):
    return (end-start) * min(fence_info[start: end])

def solution(fence_info):
    maxValue = -1
    for s in range(0, len(fence_info)-1):
        for e in range(s+1, len(fence_info)):
            maxValue = max(maxValue, getArea(fence_info, s, e))
    return maxValue


def getAreaWithStick(fence_info, idx):
    max_val = -1

    h = float('inf')

    for i in range(idx+1, len(fence_info)):
        cand = fence_info[i-1]
        h = min(cand, h)
        max_val = max(max_val,
                      (i-idx) * h
                      )


    # [start, idx)   [idx-1, -1)        idx - (idx-1)         idx -
    for i in range(1,idx+1):
        cand = fence_info[idx-i]
        h = min(cand, h)
        max_val = max(max_val,
                      (i+1) * h
                      )

    return max_val




def divide_recur(fence_info, start, end):
    if end - start == 0:
        return 0
    if end - start == 1:
        return fence_info[start]

    mid = start + (int)((end-start)/2)

    return max([divide_recur(fence_info, start, mid),
                divide_recur(fence_info, mid+1, end),
                getAreaWithStick(fence_info, mid)]
               )



def solution_divide(fence_info):
    return divide_recur(fence_info, 0, len(fence_info))




if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            num = toInteger(f.readline().split()[0])
            fence_info = [toInteger(x) for x in f.readline().split()]
            print(num)
            print(fence_info)
            print(solution(fence_info))
            print(solution_divide(fence_info))
            print()

