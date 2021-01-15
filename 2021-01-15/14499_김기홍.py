n, m, x, y, k = map(int, input().split())

graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

orders = list(map(int, input().split()))

dice = [0] * 6
tmp = [0] * 6

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

direction = [
    (2, 0, 5, 3, 4, 1),
    (1, 5, 0, 3, 4, 2),
    (4, 1, 2, 0, 5, 3),
    (3, 1, 2, 5, 0, 4)
]

# 0이면 주사위 -> 칸
# 0이 아니면 칸 -> 주사위, 칸 = 0

for order in orders:
    order -= 1
    nx = x + dx[order]
    ny = y + dy[order]
    if nx < 0 or nx >= n or ny < 0 or ny >= m:    
        continue
    for i in range(6):
        tmp[i] = dice[i]
    for i in range(6):
        dice[i] = tmp[direction[order][i]]
    if graph[nx][ny]:
        dice[5] = graph[nx][ny]
        graph[nx][ny] = 0
    else:
        graph[nx][ny] = dice[5]
    x = nx
    y = ny
    print(dice[0])