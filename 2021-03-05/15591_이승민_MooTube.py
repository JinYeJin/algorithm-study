# -*- coding: utf-8 -*-

# MooTube (Silver)
# 다익스트라

import sys
from collections import deque
input = sys.stdin.readline
vN, qN  = map(int, input().split())
g = [[] for _ in range(vN + 1)]
dp = [[0 for _ in range(vN + 1)] for _ in range(vN + 1)]
qestion = []
ans = []
for i in range(vN - 1):
    n1, n2, w = map(int, input().split())
    g[n1].append([w, n2])
    g[n2].append([w, n1])
for i in range(qN):
    k, v = map(int, input().split())
    qestion.append([k, v])
def dijkstra(k, i):
    q = deque()
    visited = [0 for _ in range(vN + 1)]
    q.append(i)
    visited[i] = 1
    minDist = sys.maxsize
    cnt = 0
    while q:
        s = q.popleft()
        for w, adj in g[s]:
            if not visited[adj]:
                visited[adj] = 1
                if w >= k:
                    cnt += 1
                    q.append(adj)
    ans.append(cnt)  
for k, v in qestion:
    dijkstra(k, v)
print("\n".join(map(str, ans)))