import sys
sys.stdin = open("input/2638.txt")

from queue import Queue
from copy import deepcopy

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def boundary(c):
    return c['y'] >= 0 and c['y'] < N and c['x'] >= 0 and c['x'] < M

def print_arr():
    for n in range(N):
        for m in range(M):
            print(grid[n][m], end=" ")
        print()


N, M = map(int, input().split())
cheese = Queue()
new_cheese = Queue()
grid = []

for n in range(N):
    temp = list(map(int, input().split()))
    for m in range(M):
        if temp[m]:
            cheese.put({'y': n, 'x':m})
    grid.append(temp)

new_grid = deepcopy(grid)
time = 0

while not cheese.empty():
    print(time)
    print_arr()
    time += 1
    while not cheese.empty():
        cur = cheese.get()
        empty = 0
        is_melt = False

        for d in range(4):
            newc = {'y': cur['y'] + dy[d], 'x': cur['x'] + dx[d]}

            if not boundary(newc):
                continue
            if not grid[newc['y']][newc['x']]: # 주변에 빈공간 세기
                empty += 1
            if empty >= 2: # 치즈가 녹는 경우
                is_melt = True
                break

        if not is_melt: # 치즈가 안녹은 경우
            new_cheese.put(cur)
            new_grid[cur['y']][cur['x']] = True
        else:
            new_grid[cur['y']][cur['x']] = False

    while(not new_cheese.empty()):
        cheese.put(new_cheese.get())
    grid = deepcopy(new_grid)

print(time)
