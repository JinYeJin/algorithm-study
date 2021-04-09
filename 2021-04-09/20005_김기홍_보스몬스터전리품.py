from collections import deque

n, m, p = map(int, input().split())

board = [list(input()) for _ in range(n)]
check = [[0] * m for _ in range(n)]

players = {}
for _ in range(p):
    player, dps = input().split()
    players[player] = int(dps)
boss = int(input())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(i, j):
    global boss
    q = deque()
    cnt = 0
    damage = 0
    q.append((i, j))
    check[i][j] = 1
    while q:
        x, y = q.popleft()
        if board[x][y] != "." and board[x][y] != "X" and board[x][y] != "B":
            cnt += 1
            damage += players[board[x][y]]
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < n and 0 <= ny < m and check[nx][ny] == 0:
                if board[nx][ny] != "X":
                    q.append((nx, ny))
                    check[nx][ny] = 1
        boss -= damage
        print(boss)
        if boss <= 0:
            return cnt


for i in range(n):
    for j in range(m):
        if board[i][j] == "B":
            print(bfs(i, j))
