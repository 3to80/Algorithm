import fileinput
from collections import defaultdict
import itertools


dx = [-1, 0, 1]
dy = [-1, 0, 1]
def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            print(arr[i][j])


def hasWord(r, c, word, board):
    if not (r in range(5) and c in range(5)):
        return False
    if board[r][c] != word[0]:
        return False
    if len(word) == 1:
        return True
    for i in dx:
        for j in dy:
            if i == 0 and j == 0:
                continue
            if hasWord(r+i, c+j, word[1:], board):
                return True
    return False



def hasWord2(board, word):
    myMap = defaultdict(lambda: [])
    for row, col in itertools.product(range(5), range(5)):
        myMap[board[row][col]].append([row,col])

    def get_nearPos(candPos, lastPos):
        """
        :param candPos: Dict<char, List[Pos]>
        :param lastPos: List[Integer]
        :return:
        """
        ret = []
        for v in candPos:
            dr = lastPos[0] - v[0]
            dc = lastPos[1] - v[1]
            if dr in (-1, 0, 1) and dc in (-1, 0, 1):
                ret.append(v)
        return ret


    def func(word, wordMap, lastPos): # word[0]에 대해 시작
        if not word:
            return True
        if word[0] not in wordMap:
            return False

        cand = get_nearPos(myMap[word[0]], lastPos)

        if not cand:
            return False

        for nextPos in cand:
            if func(word[1:], myMap, nextPos):
                return True
        return False


    if not myMap[word[0]]:
        return False

    for pos in myMap[word[0]]:
        if func(word[1:], myMap, pos):
            return True

    return False





if __name__ == '__main__':
    with fileinput.input(files=('input')) as f:
        cnt = toInteger(f.readline())
        board = [[0 for col in range(5)] for row in range(5)]
        for i in range(cnt):
            for row in range(5):
                tmp = f.readline().split()
                for col in range(5):
                    board[row][col] = tmp[0][col]
            word_num = toInteger(f.readline().split()[0])
            target = []
            for j in range(word_num):
                target.append(f.readline().split())
            print(board)
            print(word_num)
            print(target)
            for k in target:
                ret1 = False
                if hasWord2(board, k[0]):
                    ret1 = True
                print("{}: {}".format(k[0], ret1))

                ret = False
                for row in range(5):
                    for col in range(5):
                        if (hasWord(row, col, k[0], board)):
                            ret = True
                            break
                print("{}: {}".format(k[0], ret))



