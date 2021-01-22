# https://www.fun-coding.org/Chapter20-prim-live.html
# 실패
import sys
import heapq
input = sys.stdin.readline
v, e = map(int, input().split())
# e개의 입력
# 튜플의 리스트로 저장하는데 (가중치, 노드)
# 양방향 넣어 줘야 함
d = dict()
for _ in range(e):
    a, b, c = map(int, input().split())
    if a in d:
        heapq.heappush(d[a], (c, b))
    else:
        d[a] = []
        heapq.heappush(d[a], (c, b))
    if b in d:
        heapq.heappush(d[b], (c, a))
    else:
        d[b] = []
        heapq.heappush(d[b], (c, a))
# print(d)
# 프림 알고리즘 시작
# 임이의 노드로 시작해도 됨
val = 0
pos = 0
dist = [float("inf")] * (v + 1)
selected = [False] * (v + 1)
selected[0] = True
dist[1] = 0
for i in range(1, v + 1):
    now = -1
    min_dist = float("inf")
    for j in range(1, v + 1):
        if selected[j] is False and min_dist > dist[j]:
            min_dist = dist[j]
            now = j
    val += min_dist
    if now != -1:
        selected[now] = True
    for k in d[now]:
        dist[k[1]] = min(dist[k[1]], k[0])

print(val)
