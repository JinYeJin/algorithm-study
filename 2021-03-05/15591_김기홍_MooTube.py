INF = float(1e9)
n, q = map(int, input().split())


graph = [[] for _ in range(n + 1)]
check = [False] * 5001

for _ in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))


def dfs(start, nowCost, k):
    cnt = 0
    check[start] = True
    for end, cost in graph[start]:
        if check[end]:
            continue
        nextCost = min(nowCost, cost)
        if nextCost < k:
            continue
        cnt += 1 + dfs(end, nextCost, k)
    check[start] = False
    return cnt


for _ in range(q):
    k, v = map(int, input().split())
    print(dfs(v, INF, k))
