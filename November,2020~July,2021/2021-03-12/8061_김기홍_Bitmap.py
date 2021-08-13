n, m = map(int, input().split())

board = [list(map(int, input())) for _ in range(n)]

d = {}

for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            d[(i, j)] = 1

for x in range(n):
    for y in range(m):
        tmp = 999999
        if board[x][y] == 0:
            for nx, ny in d.keys():
                tmp = min(tmp, abs(x - nx) + abs(y - ny))
            board[x][y] = tmp
        else:
            board[x][y] = 0

for i in range(n):
    for j in range(m):
        print(board[i][j], end=" ")
    print()