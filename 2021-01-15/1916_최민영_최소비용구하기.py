import sys
import heapq
input = sys.stdin.readline
n = int(input())
m = int(input())
distance = [1e9] * (n + 1)
# vertex 갯수보다 1개 더 추가 0을 제외 할 생각이니
adj = [[] for _ in range(n + 1)]
def dijkstra(start):
    heap_cost = []
    # 여기서 heapq에 넣을때는 가중치가 먼저 들어오도록 넣어야 함
    heapq.heappush(heap_cost, (0, start))
    distance[start] = 0
    while heap_cost:
        cost, now = heapq.heappop(heap_cost)
        if distance[now] < cost:
            continue
        # v => 값, des => 도착지
        for v, des in adj[now]:
            now_cost = cost + v
            if now_cost < distance[des]:
                distance[des] = now_cost
                heapq.heappush(heap_cost, (now_cost, des))



for _ in range(m):
    st, end, val = map(int, input().split())
    # 넣을때는 편한대로 넣으면 됨 => 현재는 (가중치, 목적지) 형태로 삽입
    adj[st].append((val, end))
sc, de = map(int, input().split())
dijkstra(sc)
print(distance[de])
