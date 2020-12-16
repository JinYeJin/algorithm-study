import sys
from collections import deque


def bfs():
    attached = 0
    visited = [[False for _ in range(M)] for _ in range(N)]
    q = deque([ice[0]])
    visited[ice[0][0]][ice[0][1]] = True
    while q:
        x, y = q.popleft()
        zero_count = 0
        attached += 1
        for dx, dy in (1, 0), (0, 1), (-1, 0), (0, -1):
            nx, ny = x + dx, y + dy
            if visited[nx][ny]:
                continue
            if board[nx][ny] == 0:
                zero_count += 1
                continue
            if board[nx][ny] > 0:
                visited[nx][ny] = True
                q.append((nx, ny))

        if board[x][y] - zero_count != 0:
            board[x][y] -= zero_count
        else:
            board[x][y] = -1

    return attached


N, M = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

ice = []
for i in range(N):
    for j in range(M):
        if board[i][j]:
            ice.append((i, j))

c = 0
while True:
    new_ice = []
    if len(ice) == 0:
        c = 0
        break
    a = bfs()
    if len(ice) != a:
        break
    for (x, y) in ice:
        if board[x][y] < 0:
            board[x][y] = 0
        else:
            new_ice.append((x, y))

    ice = new_ice[:]
    c += 1

print(c)
