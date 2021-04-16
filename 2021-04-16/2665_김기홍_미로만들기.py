from collections import deque

n = int(input())

board = [list(map(int, input())) for _ in range(n)]
check = [[-1] * n for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(i, j):
    q = deque()
    q.append((i, j))
    check[i][j] = 0

    while q:
        x, y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < n and 0 <= ny < n:
                if check[nx][ny] == -1:
                    if board[nx][ny] == 0:
                        check[nx][ny] = check[x][y] + 1
                        q.append((nx, ny))
                    else:
                        check[nx][ny] = check[x][y]
                        q.appendleft((nx, ny))

bfs(0, 0)
print(check[n - 1][n - 1])
