from collections import deque

n = int(input())
k = int(input())

graph = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(k):
    x, y = map(int, input().split())
    graph[x][y] = 1

l = int(input())

move = []
for _ in range(l):
    time, direction = input().split()
    move.append((int(time), direction))

q = deque()

# 동 남 서 북
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def turn(direction, c):
    if c == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction


x, y = 1, 1
graph[x][y] = 2
direction = 0
time = 0
index = 0
q.append((x, y))

while True:
    nx = x + dx[direction]
    ny = y + dy[direction]
    if nx >= 1 and nx <= n and ny >= 1 and ny <= n and graph[nx][ny] != 2:
        if graph[nx][ny] == 0:
            graph[nx][ny] = 2
            q.append((nx, ny))
            px, py = q.popleft()
            graph[px][py] = 0

        if graph[nx][ny] == 1:
            graph[nx][ny] = 2
            q.append((nx, ny))
    else:
        time += 1
        break
    # 뱀 머리 갱신
    x, y = nx, ny
    time += 1
    if index < l and time == move[index][0]:
        print(index)
        direction = turn(direction, move[index][1])
        index += 1

print(time)

