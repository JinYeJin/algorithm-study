from collections import deque

n = int(input())

graph = [[] for _ in range(n + 1)]


for _ in range(n):
    arr = list(map(int, input().split()))
    for i in range(1, len(arr) - 1, 2):
        graph[arr[0]].append((arr[i], arr[i + 1]))

# bfs

def bfs(start):
    check = [-1] * (n + 1)
    q = deque()
    q.append(start)
    check[start] = 0
    _max = [0, 0]
    
    while q:
        before = q.popleft()
        for v, e in graph[before]:
            if check[v] == -1:
                check[v] = check[before] + e
                q.append(v)
                if _max[0] < check[v]:
                    _max = check[v], v
    return _max

dis, node = bfs(1)
dis, node = bfs(node)
print(dis)