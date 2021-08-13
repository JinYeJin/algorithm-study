#1. 입력(노드, 간선, 시작 지점, 도착 지점)을 받는다.
#2. 1차원 배열에 거리의 값을 무한대로 초기화해서 저장한다. (시작 위치는 0으로 초기화한다.)
#3. 우선 순위 큐를 사용해서 최단거리에 있는 노드를 선택하고 그 노드와 인접된 노드까지의 거리를 계산한다.
#이미 계산한 거리보다 더 작은 거리 값이 나온다면 값을 업데이트하고 인접한 노드를 우선순위 큐에 추가한다.
#4. 우선순위 큐가 빌 때까지 3번 과정을 반복한다.

import sys
from heapq import heappush, heappop

def dijkstra(start):
  dist[start]=0
  heap=[]
  heappush(heap, [start, 0])
  while heap:
    x,y=heappop(heap)
    if dist[x]<y:
      continue
    for e,c in city[x]:
      cost=y+c
      if cost<dist[e]:
        dist[e]=cost
        heappush(heap, [e,cost])
  return dist[e]

input=sys.stdin.readline
n=int(input())
m=int(input())
inf=100000000
dist=[inf for _ in range(n+1)]
city=[[] for _ in range(n+1)]
for _ in range(m):
  s,e,c=map(int, input().split())
  city[s].append([e,c])
start,end=map(int, input().split())
print(dijkstra(start))
