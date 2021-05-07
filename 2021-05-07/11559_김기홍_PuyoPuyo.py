from collections import deque


def bfs(i, j, check):
    array = []
    q = deque()
    q.append((i, j))
    check[i][j] = 0
    array.append((i, j))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and check[nx][ny] == -1 and b[nx][ny] != ".":
                if b[nx][ny] == b[x][y]:
                    check[nx][ny] = 0
                    q.append((nx, ny))
                    array.append((nx, ny))
    if len(array) >= 4:
        return array
    else:
        return []


def puyo():
    pop_set = set()
    check = [[-1] * 12 for _ in range(6)]
    for i in range(n):
        for j in range(m):
            if b[i][j] != '.' and check[i][j] == -1:
                pop_set |= set(bfs(i, j, check))

    for i, j in pop_set:
        b[i][j] = 0
    for i, row in enumerate(b):
        empty = ['.'] * row.count(0)
        b[i] = empty + [block for block in row if block != 0]
    return len(pop_set)


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
board = []
m = 12
n = 6
for _ in range(12):
    board.append(list(input()))

cnt = 0
b = list(map(list, zip(*board)))
while True:
    p = puyo()
    if p != 0:
        cnt += 1
    else:
        break
print(cnt)
