INF = float(1e9)

n, m, x= map(int, input().split())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(n + 1):
    for j in range(n + 1):
        if i == j:
            graph[i][j] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

result = []

for i in range(1, n + 1):
    go = graph[i][x]
    back = graph[x][i]
    result.append(go + back)

result.sort()

print(result[-1])
        