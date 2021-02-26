n, m = map(int, input().split())

graph = [[] for _ in range(n)]
check = [False] * 2001 

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

isabc = False

def dfs(start, cnt):
    global isabc
    if cnt == 5:
        isabc = True
        return
    check[start] = True
    for end in graph[start]:
        if check[end] == False:
            dfs(end, cnt + 1)
    check[start] = False

for i in range(n):
    if isabc:
        break
    dfs(i, 1)

if isabc:
    print(1)
else:
    print(0)