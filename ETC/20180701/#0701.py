# Write a function to flatten the nesting in an arbitrary list of values. Your program should work on the equivalent of this list:
#
#  [[1], 2, [[3,4], 5], [[[]]], [[[6]]], 7, 8, []]
#
#
#
# Where the correct result would be the list:
#
#   [1, 2, 3, 4, 5, 6, 7, 8]


from collections import deque


def solve(input):
    """
    input의 brace들을 다 벗겨 list로 반환하는 함수
    :param input: List
    :return: List
    """
    ret = []

    queue = deque(input)
    while queue:
        target = queue.popleft()
        if isinstance(target, list):
            for i in target:
                queue.appendleft(i)
        else:
            ret.append(target)

    return ret


def push_delayed(li, ret):
    if len(li) > 0:
        push_delayed(li[1:], ret)
        ret.appendleft(li[0])


def solve2(input):
    ret = []
    queue = deque(input)
    while queue:
        target = queue.popleft()
        if isinstance(target, list):
            push_delayed(target, queue)
        else:
            ret.append(target)

    return ret


def solve_easy(src, ret):
    if isinstance(src, list):
        for i in src:
            solve_easy(i, ret)
    else:
        ret.append(src)


def solve3(src, ret, level):
    if isinstance(src, list):
        tmp = 0
        for i in src:
            tmp += solve3(i, ret, level+1)
        return tmp

    else:
        ret.append(src)
        print(src, level)
        return src * level

def solve4(src, ret, current_level, max_level):
    if isinstance(src, list):
        tmp = 0
        for i in src:
            tmp += solve3(i, ret, current_level + 1)
        return tmp

    else:
        ret.append(src)
        print(src, current_level)
        return src * (max_level- current_level)


# f([[1], 2], max_level)
# - ret = f([1], max_level) + f(2, max_level)
# f([1], max_level)
#     - ret = f(1, max_level, current_level)
# f(2, max_level)
#     - ret = 2 * (max_level-current)


# f(src, current_level, max_level):
#   if src is list:
#       tmp = 0
#       for i in src:
#           tmp += f(src, current_level, max_level):
#           return tmp

# Write a function to flatten the nesting in an arbitrary list of values. Your program should work on the equivalent of this list:
#
#  [[1], 2, [[3,4], 5], [[[]]], [[[6]]], 7, 8, []]
#
#
#
# Where the correct result would be the list:
#
#   [1, 2, 3, 4, 5, 6, 7, 8]


from collections import deque


def solve(input):
    """
    input의 brace들을 다 벗겨 list로 반환하는 함수
    :param input: List
    :return: List
    """
    ret = []

    queue = deque(input)
    while queue:
        target = queue.popleft()
        if isinstance(target, list):
            for i in target:
                queue.appendleft(i)
        else:
            ret.append(target)

    return ret


def push_delayed(li, ret):
    if len(li) > 0:
        push_delayed(li[1:], ret)
        ret.appendleft(li[0])


def solve2(input):
    ret = []
    queue = deque(input)
    while queue:
        target = queue.popleft()
        if isinstance(target, list):
            push_delayed(target, queue)
        else:
            ret.append(target)

    return ret


def solve_easy(src, ret):
    if isinstance(src, list):
        for i in src:
            solve_easy(i, ret)
    else:
        ret.append(src)


def solve3(src, ret, level):
    if isinstance(src, list):
        tmp = 0
        for i in src:
            tmp += solve3(i, ret, level+1)
        return tmp

    else:
        ret.append(src)
        print(src, level)
        return src * level


def solve4(src, level):
    if isinstance(src, list):
        max_val = -float('inf')
        for i in src:
            max_val = max(max_val, solve4(i, level+1))
        return max_val
    else:
        return level


def solve5(src, level, max_level):
    if isinstance(src, list):
        tmp = 0
        for i in src:
            tmp += solve5(i, level+1, max_level)
        return tmp

    else:
        return src * (max_level - level)



if __name__ == '__main__':
    input1 = [[1], 2, [[3,4], 5], [[[]]], [[[6]]], 7, 8, [9, [10, 11], [12, [13]]]]
        # print(solve2(input1))
    ret = []
    result = 0
    print(solve3(input1, ret, 0))
    max_depth = solve4(input1, 0)
    print(max_depth)
    print(solve5(input1, 0, max_depth))




