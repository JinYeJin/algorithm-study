# dfs--------------------------

import sys
sys.setrecursionlimit(10000)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

m, n = map(int, input().split())

array = []
for _ in range(m):
    array.append(list(map(int, input().split())))

visited = [[-1] * n for _ in range(m)]

def dfs(x, y):
    if x == m -1 and y == n - 1:
        return 1
    if visited[x][y] != -1:
        return visited[x][y]
    visited[x][y] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= m or ny < 0 or ny >= n or array[x][y] <= array[nx][ny]:
            continue
        visited[x][y] += dfs(nx, ny)

    return visited[x][y]

print(dfs(0, 0))

# bfs-------------------------
