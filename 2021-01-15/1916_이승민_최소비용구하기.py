# 최소비용 구하기
# 구현 아이디어 : 최소 힙을 이용해서 [가중치, 노드 번호] 형식의 리스트로 저장 후
# 다익스트라 알고리즘 구현

import sys
import heapq

input = sys.stdin.readline
nC = int(input()) # num of City -> 노드의 개수
nB = int(input()) # num of Bus -> 간선의 개수
adj = [[] for _ in range(nC + 1)] # 인접한 노드
d = [10 ** 8] * (nC + 1)
for i in range(nB):
    s, e, w = map(int, input().split()) # start, end, weight
    adj[s].append([w, e])
a, b = map(int, input().split())

def dij():
    h = [] # heap
    d[a] = 0
    heapq.heappush(h, [d[a], a]) # 0 1
    while h:
        cur = h.pop()
        dist = cur[0] # 0
        idx = cur[1] # 1
        if d[idx] != dist:
            continue
        for nxt in adj[idx]:
            cost = nxt[0]
            nidx = nxt[1]
            if d[nidx] > dist + cost:
                d[nidx] = dist + cost
                heapq.heappush(h, [d[nidx], nidx])
    print(d[b])
dij()

# Max Heap 구현
# for num in nums:
#   heapq.heappush(heap, (-num, num))  # (우선 순위, 값)

