import fileinput


def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        tmp = str()
        for j in range(len(arr[0])):
            if arr[i][j]:
                tmp += '.'
            else:
                tmp += '#'
        print(tmp)


def get_white_num(board):
    ret = 0
    for row in board:
        for itm in row:
            if itm:
                ret += 1
    return ret


# def len_square(p0, p1):
#     return (p0[0] - p1[0]) * (p0[0] - p1[0]) + (p0[1] - p1[1]) * (p0[1] - p1[1])
#
#
# def test(itms):
#     # print(itms)
#     #p1을 기준
#     tmp = []
#
#     i = 0
#     while i < len(itms):
#         idx1 = i % len(itms)
#         idx2 = (i+1) % len(itms)
#         tmp.append(len_square(itms[idx1], itms[idx2]))
#         i += 1
#     tmp.sort()
#     return tmp[-1] == 2 and tmp[-1]*2 == sum(tmp)
#
#
# def ableToFill(board):
#     """
#
#     :param board:
#     :return: Boolean
#     """
#     itms = []
#     for row in range(len(board)):
#         for col in range(len(board[0])):
#              if board[row][col]:
#                  itms.append([row, col])
#
#     return test(itms)


def make_dir(r, c):# 강제한다는거 생각, 여기서 강제를 해야만 됬고, 그러려면 모든 방향이 아니라 현 정점이 가장 왼쪽 오른쪽에 있게 했어야 된다.
    """

    :param r: int
    :param c: int
    :return: List[List[List[Integer]]]
    """
    ret = []
    ret.append([[r, c], [r+1, c], [r+1, c+1]])
    ret.append([[r, c], [r+1, c], [r+1, c-1]])
    ret.append([[r, c], [r, c+1], [r+1, c+1]])
    ret.append([[r, c], [r, c+1], [r+1, c]])

    return ret


# nRange([x[1], x[2]], [len(board), len(board[0])])
def inRange(li, rng):
    for i in li:
        if not(i[0] in range(rng[0]) and i[1] in range(rng[1])):
            return False

    return True


def check(board, tmp):
    return board[tmp[0]][tmp[1]]


def solve(board, rem_white):






    # 그다음에 갈 곳을 찾는다.
    next_point = []
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col]:
                next_point=[row,col]
                break
        if next_point:
            break

    if not next_point:
        return 1

    ret = 0
    row = next_point[0]
    col = next_point[1]

    if board[row][col]:
        for target_one in [x for x in make_dir(row,col) if inRange([x[1], x[2]], [len(board), len(board[0])])
                  and check(board, x[1]) and check(board, x[2])]:

            board[row][col] = False
            board[target_one[1][0]][target_one[1][1]] = False
            board[target_one[2][0]][target_one[2][1]] = False
            ret += solve(board, rem_white-3)
            board[target_one[1][0]][target_one[1][1]] = True
            board[target_one[2][0]][target_one[2][1]] = True
            board[row][col] = True

    return ret


if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            H = toInteger(t[0])
            W = toInteger(t[1])
            MAX_ROW = H
            MAX_COL = W
            board = [[] for row in range(H)]
            for row in range(H):
                tmp = f.readline().split()[0]
                for i in tmp:
                    if i == '.':
                        board[row].append(True)
                    else:
                        board[row].append(False)

            ret = 0
            rem_white = get_white_num(board)
            if not rem_white % 3:
                ret = solve(board, rem_white)

            else:
                ret = 0
            print("ret: ", ret)
            # print(rem_white, ret)