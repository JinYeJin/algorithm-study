from collections import deque
import sys
input = sys.stdin.readline
m, n, k = map(int, input().split())
rectangle = [[0] * n for _ in range(m)]
visited = [[False] * n for _ in range(m)]
mv = [(0, 1), (0, -1), (1, 0), (-1, 0)]
xy_list = []
size_list = []
for _ in range(k):
    f_x, f_y, l_x, l_y = map(int, input().split())
    for j in range(f_y, l_y):
        for i in range(f_x, l_x):
            rectangle[j][i] += 1
def bfs(a, b):
    global visited
    q = deque()
    q.append((a, b))
    visited[a][b] = True
    area = 0
    while q:
        x, y = q.popleft()
        rectangle[x][y] += 1
        area += 1
        for mx, my in mv:
            nx = x + mx
            ny = y + my
            if 0 <= nx < m and 0 <= ny < n and rectangle[nx][ny] == 0 and visited[nx][ny] is False:
                q.append((nx, ny))
                visited[nx][ny] = True
    return area
for i in range(m):
    for j in range(n):
        if rectangle[i][j] == 0:
            s = bfs(i, j)
            size_list.append(s)
size_list.sort()
print(len(size_list))
print(" ".join(map(str, size_list)))