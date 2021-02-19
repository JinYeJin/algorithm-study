from collections import deque

INF = float(1e9)

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

m, n = map(int, input().split())

board = [list(map(int, input())) for _ in range(n)]

distance = [[INF] * m for _ in range(n)]

q = deque()

q.append((0, 0))
distance[0][0] = 0

while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if distance[x][y] + board[nx][ny] < distance[nx][ny]:
            distance[nx][ny] = distance[x][y] + board[nx][ny]
            q.append((nx, ny))

print(distance[n - 1][m - 1])
