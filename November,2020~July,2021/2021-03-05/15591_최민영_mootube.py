# 각 정점에서 갈 수 있는 거리중 가장 작은 것을 찾기 => 문제를 거꾸로 생각하기
import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline
n, q_number = map(int, input().split())
graph = defaultdict(list)
visited = [False] * n
# bfs로 k이상인 것들 찾아서 cnt
# 유사도의 경우 가장 작은 것을 유사도로 고려함
# 하지만 구하고자 하는 값은 k값 이상을 원함
# 그러므로 k끼리 중에 가장 작은 것을 상호간에 연관 동영상으로 한다고 했으니까 구하고자 하는 k값 이상이 되려면 최소가 k값 이상이 되어야 연관되어서 계속 뻗어 나갈 수 있음
# 그러므로 k이상이 될 경우에만 cnt를 하고 값을 추가함
# 다음 트리에서 k값보다 작은 값이 나온다면 그 값이 최소 값으로 현재 시작된 곳과 새로 연결되는 곳의 유사도가 되니 cnt할 수 없음
def bfs(k_val, x):
    qu = deque([(x, 0)])
    cnt = 0
    while qu:
        now, val = qu.popleft()
        for i, v in graph[now]:
            if visited[i] is False and v >= k_val:
                visited[i] = True
                cnt += 1
                qu.append((i, v))
                print("i, ", i, "v", v)
    return cnt
for _ in range(n - 1):
    p, q, r = map(int, input().split())
    graph[p - 1].append((q - 1, r))
    graph[q - 1].append((p - 1, r))
for _ in range(q_number):
    k, video = map(int, input().split())
    visited[video - 1] = True
    print(bfs(k, video - 1))
    visited = [False] * n

