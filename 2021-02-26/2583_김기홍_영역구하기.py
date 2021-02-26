import sys
sys.setrecursionlimit(10**6)
n, m, k = map(int, input().split())

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

maze = [[0] * m for _ in range(n)]

for i in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            maze[i][j] = 1

cnt = 0
def dfs(x, y):
    global cnt
    maze[x][y] = 1
    cnt += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx >= 0 and nx < n and ny >= 0 and ny < m and maze[nx][ny] == 0:
            dfs(nx, ny)


ans = []

for i in range(n):
    for j in range(m):
        if maze[i][j] == 0:
            cnt = 0
            dfs(i, j)
            ans.append(cnt)

ans.sort()
print(len(ans))
for c in ans:
    print(c, end=' ')
