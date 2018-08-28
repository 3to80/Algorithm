import fileinput


def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            print(arr[i][j])



def reverseQTree2(iter):
    """
    cur 지점을 root로 하는 subTree의 reverse 모양
    :param iter: source
    :return: string
    """
    target = iter.__next__()

    if target == 'x':
        next1 = reverseQTree2(iter)
        next2 = reverseQTree2(iter)
        next3 = reverseQTree2(iter)
        next4 = reverseQTree2(iter)

        return ''.join([target, next3, next4, next1, next2])
    else:
        return target


def reverseQTree(string, cur):
    """
    cur 지점을 root로 하는 subTree의 reverse 모양
    :param string: source
    :param current: subRoot position
    :return: [current를 노드로 했을 때, reeverse 된 Q-Tree, nextPos]
    """
    if string[cur] == 'x':
        tmp = ['x']
        cur = cur + 1
        next1 = reverseQTree(string, cur)
        next2 = reverseQTree(string, next1[1])
        next3 = reverseQTree(string, next2[1])
        next4 = reverseQTree(string, next3[1])
        tmp.append(next3[0])
        tmp.append(next4[0])
        tmp.append(next1[0])
        tmp.append(next2[0])

        return [''.join(tmp), next4[1]]
    else:
        return [string[cur], cur+1]

if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            print(t)
            print(reverseQTree(t[0], 0)[0])
            print(reverseQTree2(t[0].__iter__()))

