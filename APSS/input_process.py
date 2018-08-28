import fileinput


def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])


if __name__ == '__main__':
    with fileinput.input(files=('../input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):
            t = f.readline().split()
            H = toInteger(t[0])
            W = toInteger(t[1])
            board = [0 for row in range(H)]
            for row in range(H):
                board[row] = list(f.readline().split())



# import sys
# rl = lambda: sys.stdin.readline()
# n = int(rl())
# for i in range(n):
#   print "Hello, %s!" % rl().strip()