def solve(n, k):
    arr = [[[0 for k in range(k+1)] for n in range(n+1)] for flag in range(2)]
    # arr[flag][n][j]

    for i in range(0, n+1):
        for j in range(0, min(i+1,k+1)):
            if i == 1 and j == 0:
                arr[0][1][0] = 1
                arr[1][1][0] = 1
                continue
            if j == 0:
                arr[1][i][j] = arr[0][i - 1][j]
            else:
                arr[1][i][j] = arr[0][i - 1][j] + arr[1][i - 1][j - 1]

            arr[0][i][j] = arr[0][i - 1][j] + arr[1][i - 1][j]

    return arr[0][n][k] + arr[1][n][k]


if __name__ == '__main__':
    print(solve(20, 8))
