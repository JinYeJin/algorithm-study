from collections import deque

n, l, r = map(int, input().split())

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

ground = []
for _ in range(n):
    ground.append(list(map(int, input().split())))

def bfs(i, j):
    q = deque()
    pos = []
    q.append((i, j))
    check[i][j] = 1
    total, country = 0, 0
    while q:
        x, y = q.popleft()
        pos.append((x, y))
        total += ground[x][y]
        country += 1
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx >= 0 and nx < n and ny >= 0 and ny < n and check[nx][ny] == -1:
                if l <= abs(ground[x][y] - ground[nx][ny]) <= r:
                    q.append((nx, ny))
                    check[nx][ny] = 1
    
    for x, y in pos:
        ground[x][y] = total // country
    
    if country == 1:
        return 0
    return 1

answer = 0

while True:
    cnt = 0

    check = [[-1] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if check[i][j] == -1:
                cnt += bfs(i, j)

    if not cnt:
        break
    answer += 1

print(answer)