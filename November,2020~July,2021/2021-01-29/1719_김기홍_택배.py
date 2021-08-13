INF = 1001

n, m = map(int, input().split())

graph = [[INF] * (n + 1) for _ in range(n + 1)]
graph_node = [[-1] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            graph[i][j] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c
    graph[b][a] = c
    graph_node[a][b] = b
    graph_node[b][a] = a

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k] + graph[k][j]
                graph_node[i][j] = graph_node[i][k]


for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            print("-", end=" ")
        else:
            print(graph_node[i][j], end=" ")
    print()
