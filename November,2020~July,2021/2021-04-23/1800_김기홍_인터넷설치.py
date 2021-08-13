import heapq

INF = int(1e9)

def dijkstra(start, mid):
    q = []
    heapq.heappush(q, (0, start))
    distance[0] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue

        for i in graph[now]:
            # 노드까지의 총 거리
            # k 값 이하로 이을 수 있는지
            if i[1] > mid:
                if dist + 1 < distance[i[0]]:
                    distance[i[0]] = dist + 1
                    heapq.heappush(q, (dist + 1, i[0]))
            else:
                if dist < distance[i[0]]:
                    distance[i[0]] = dist
                    heapq.heappush(q, (dist, i[0]))
    if distance[n] > k:
        return False
    else:
        return True


n, p, k = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for _ in range(p):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

left, right = 0, 1000001

answer = INF
distance = [INF] * (n + 1)
while left <= right:
    distance = [INF] * (n + 1)
    mid = (left + right) // 2
    if dijkstra(1, mid):
        right = mid - 1
        answer = mid
    else:
        left = mid + 1

if distance[n] == INF:
    print(-1)
else:
    print(answer)
