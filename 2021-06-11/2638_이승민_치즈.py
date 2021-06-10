# -*- coding: utf-8 -*-

# 치즈
# 시간 : 2시간
# 구현 아이디어 : bfs

import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]
d = [[-1, 0], [1, 0], [0, -1], [0 ,1]]
ans = 0 # 답

def bfs(i, j):
    q = deque()
    q.append([i, j])
    visited[i][j] = 1
    while q:
        i, j = q.popleft()
        cnt = 0 # 주변 -1 개수
        for k in range(4):
            ni = i + d[k][0]
            nj = j + d[k][1]
            if g[ni][nj] == 1:
                if not visited[ni][nj]:
                    visited[ni][nj] = 1
                    q.append([ni, nj])
            elif g[ni][nj] == -1:
                cnt += 1
        # 치즈 주변에 -1이 2개 이상일 때만 set에 좌표 넣기
        if cnt >= 2:
            s.add((i, j))

# 바깥 부분이 0 또는 -1일 때 -1로 바꾸기
def outsideChange():
    q = deque()
    q.append([0, 0])
    visited[0][0] = 1
    while q:
        i, j = q.popleft()
        g[i][j] = -1
        for k in range(4):
            ni = i + d[k][0]
            nj = j + d[k][1]
            if g[ni][nj] == 0 or g[ni][nj] == -1:
                if not visited[ni][nj]:
                    visited[ni][nj] = 1
                    q.append([ni, nj])

# 맵을 한 바퀴 돌고 난 후 녹은 치즈를 -1로 바꾸기
def change():
    while s:
        i, j = s.pop()
        g[i][j] = -1

while 1:
    visited = [[0 for _ in range(m)] for _ in range(n)]
    s = set() # 바꿀 좌표
    outsideChange()
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if g[i][j] == 1 and not visited[i][j]:
                bfs(i, j)
    # 변경될 좌표가 없다면 출력
    if not s:
        print(ans)
        quit(0)

    change()
    # 변경 하고 난 후 횟수 증가
    ans += 1

# Test Case
# 3 3
# 0 0 0
# 0 1 0
# 0 0 0
# 답 : 1

# 5 4
# 0 0 0 0
# 0 1 1 0
# 0 1 1 0
# 0 0 1 0
# 0 0 0 0
# 답 : 2

# 5 4
# 0 0 0 0
# 0 1 1 0
# 0 1 1 0
# 0 1 1 0
# 0 0 0 0
# 답 : 2

# 7 9
# 0 0 0 0 0 0 0 0 0
# 0 1 1 0 0 0 1 1 0
# 0 1 0 1 1 1 0 1 0
# 0 1 0 0 1 0 0 1 0
# 0 1 0 1 1 1 0 1 0
# 0 1 1 0 0 0 1 1 0
# 0 0 0 0 0 0 0 0 0
# 답 : 3