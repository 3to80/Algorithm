# 시도 1
def f(arr, start_idx, remainder):
    """

    :param arr: read-only, src
    :param start_idx: [start_idx: ]
    :param remainder: pick the number of remainder
    :return: List[List[Integer]] ; [[1,2], [1, 3], [2, 3]]
    """
    #base case
    if start_idx < len(arr) and remainder == 0:
        ret = []
        for i in arr[start_idx:]:
            ret.append([i])
        return ret
    #loop case
    else:
        print(start_idx, remainder)

        tmp = f(arr, start_idx+1, remainder-1)
        for i in tmp:
            i.append(arr[start_idx])
        return f(arr, start_idx+1, remainder).extend(tmp)


# 시도 2
#
# [1,2,3] , (0, 2)
#
#  ->f([2,3] , (0, 2))  + a(1) * f([2,3] , (1, 1))
#  -> [[2,3]] + [1] * f([2,3] , (0, 1))
#
# f([2,3] , (0, 1))
# -> a(2) * f([3], (2, 0)) + f([3] , (2, 1))
# [[2]]
# f([3] , (2, 1))
# -> a(3) * f([[3]], (3, 0)) + f([[3]], (3, 1))
#
#
# f([0, 1], 0, 1):
#
# f([0, 1], 1, 1):
# f([0, 1], 1, 0):

def f2(arr, start_idx, remainder, prefix):
    if remainder == 0:
        return prefix
    if remainder > 0 and start_idx+remainder <= len(arr):
        for i in arr[start_idx:]:
            for j in prefix:
                j.append(i)
        f2(arr, start_idx+1, remainder-1, prefix)

if __name__ == '__main__':
    print(f2([1,2,3], 0, 1,[[]]))

