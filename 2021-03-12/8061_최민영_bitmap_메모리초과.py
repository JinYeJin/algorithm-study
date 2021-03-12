from collections import deque
n, m = map(int, input().split())
pixels = []
d = [[0] * m for _ in range(n)]
for _ in range(n):
    pixels.append(list(map(int, input().strip())))
mv = [(1, 0), (-1, 0), (0, 1), (0, -1)]
def bfs(i, j):
    if pixels[i][j] == 1:
        return 0
    q = deque([(i, j, 0)])
    visited = [[False] * m for _ in range(n)]
    visited[i][j] = True
    while q:
        x, y, cnt = q.popleft()
        if pixels[x][y] == 1:
            return cnt
        for mx, my in mv:
            nx = x + mx
            ny = y + my
            if 0 <= nx < n and 0 <= ny < m:
                q.append((nx, ny, cnt + 1))
for i in range(n):
    for j in range(m):
        d[i][j] = bfs(i, j)
for _ in d:
    print(" ".join(map(str,_)))
