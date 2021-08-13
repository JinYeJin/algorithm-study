n = int(input())

graph = [[] for _ in range(n + 1)]

for i in range(n - 1):
    a, b = map(int, input().split())
    graph[b].append(a)

answer = []
ispossible = True

check = [False] * (n + 1) 

def dfs(i, j):
    if i == j:
        return True

    check[i] = True
    for to in graph[i]:
        if not check[to]:
            dfs(to, j)
    check[i] = False

    return False

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i != j:
            ispossible = True
            if not dfs(i, j):
                ispossible = False
        if ispossible:
            answer.append(i)

answer.sort()

if answer:
    print(answer[0])
else:
    print(-1)