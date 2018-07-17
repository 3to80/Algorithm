from copy import deepcopy

def pick(n, k, picked, ret):
    # n개에서 k개의 숫자를 뽑기.
    if k == 0:
        ret.append(deepcopy(picked))

        return
    smallest = 0
    if picked:
        smallest = picked[-1]+1
    for i in range(smallest, n):
        picked.append(i)
        pick(n, k-1, picked, ret)
        picked.pop()


def permutation(src, ret, picked):
    if not src:
        ret.append(deepcopy(picked))
        return
    for i in range(len(src)):
        next_string  = src[:i] + src[i+1:]
        picked.append(src[i])
        permutation(next_string, ret, picked)
        picked.pop()


def picked_and_permuated(string, k, picked, ret):
    # n개에서 k개의 숫자를 뽑기.
    if k == 0:
        substring= ''.join([string[i] for i in picked])
        permutation(substring, ret, [])
        return
    smallest = 0
    if picked:
        smallest = picked[-1] + 1
    for i in range(smallest, len(string)):
        picked.append(i)
        pick(len(string), k - 1, picked, ret)
        picked.pop()


if __name__ == '__main__':
    ret = []
    picked_and_permuated("asdf", 2, [], ret)
    print(ret)


