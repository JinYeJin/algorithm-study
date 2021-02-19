# bfs 이용하여서 업데이트 시키는 형태로 진행
# 1이면 더하기
# 행은 m 열은 n
from collections import deque
import heapq
n, m = map(int, input().split())
maze = []
mv = ((0, 1), (1, 0), (0, -1), (-1, 0))
for _ in range(m):
    maze.append(list(map(int,input().strip())))
visited = [[0] * n for _ in range(m)]
result = [[0] * n for _ in range(m)]
q = []
heapq.heappush(q, (0, 0, 0))
while q:
    v, x, y = heapq.heappop(q)
    if x == m - 1 and y == n - 1:
        print(v)
        exit(0)
    if visited[x][y] != 0:
        continue
    visited[x][y] += 1
    if maze[x][y] == 1:
        nv = v + 1
    else:
        nv = v
    for mx, my in mv:
        nx = x + mx
        ny = y + my
        if 0 <= nx < m and 0 <= ny < n:
            heapq.heappush(q, (nv, nx, ny))
