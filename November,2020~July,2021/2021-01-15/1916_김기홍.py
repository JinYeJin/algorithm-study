import heapq
import sys
input = sys.stdin.readline
n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
distance = [float('inf')] * (n + 1)

for _ in range(m):
    start, end, cost = map(int, input().split())
    graph[start].append((end, cost))
    # graph[end].append((start, cost))


start, end = map(int, input().split())


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijkstra(start)

print(distance[end])
