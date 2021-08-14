import sys
sys.stdin = open("input/2589.txt")

from collections import deque

def bounday(x, y):
    return (0 <= x < C) and (0 <= y < R)

R, C = map(int, input().split())
island = []

for r in range(R):
    line = input()
    temp = []
    for c in range(C):
        temp.append(line[c])
    island.append(temp)


time = 0

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for r in range(R):
    for c in range(C):
        if island[r][c] == "L":
            visited = [[False] * C for _ in range(R)]
            start = [r, c, 0]
            path = deque()
            path.append(start)

            while(path):
                # r, c, distance
                current = path.popleft()
                # print(current)
                y = current[0]
                x = current[1]
                distance = current[2]

                if visited[y][x]:
                    continue

                visited[y][x] = True
                time = distance if distance > time else time

                # for i in range(R):
                #     for j in range(C):
                #         print("O" if visited[i][j] else "X", end="")
                #     print()

                for d in range(4):
                    ny = y + dy[d]
                    nx = x + dx[d]

                    next = [ny, nx, distance + 1]
                    if not bounday(nx, ny): # 바운더리 넘어감
                        continue
                    if island[ny][nx] == "W": # 바다 못감
                        continue
                    path.append(next)

print(time)
