import sys
n = int(input())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

board = []
T_pos = []
check_point = []

for _ in range(n):
    board.append(list(input().split()))

for i in range(n):
    for j in range(n):
        if board[i][j] == 'T':
            T_pos.append((i, j))

for x, y in T_pos:
    for i in range(4):
        for j in range(1, 5):
            nx = x + dx[i] * j
            ny = y + dy[i] * j
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if j == 1 and board[nx][ny] == 'S':
                print("NO")
                sys.exit(0)
            if board[nx][ny] == 'S':
                check_point.append((nx - dx[i], ny - dy[i]))
            

print(check_point)