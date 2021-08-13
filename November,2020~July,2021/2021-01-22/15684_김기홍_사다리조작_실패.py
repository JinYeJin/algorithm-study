n, m, h = map(int, input().split())

graph = [[0] * (n + 1) for _ in range(h + 1)]

for i in range(m):
    # a는 가로 위치, b는 b + 1까지 연결
    a, b = map(int, input().split())
    graph[a][b] = 1

def check():
    for i in range(1, n + 1):
        start = i
        for j in range(1, h + 1):
            if graph[j][start]:
                start += 1
            elif start - 1 >= 1 and graph[j][start - 1]:
                start -= 1
        if start != i:
            return 0
    return 1

