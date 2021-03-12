# -*- coding: utf-8 -*-

# Milk Factory
import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
g = [[] for _ in range(n + 1)]
ans = [sys.maxsize] * (n + 1)
for i in range(n - 1):
    n1, n2 = map(int, input().split())
    g[n1].append(n2)

def bfs(i):
    global ans
    q = deque()
    visited = [0] * (n + 1)
    q.append(i)
    visited[i] = 1
    while q:
        s = q.popleft()
        for adj in g[s]:
            if not visited[adj]:
                visited[adj] = 1
                if ans[adj] == sys.maxsize:
                    ans[adj] = 1
                else:
                    ans[adj] += 1
                q.append(adj)
for i in range(1, n + 1):
    bfs(i)
if n == 1:
    print(0)
else:
    print(min(ans))