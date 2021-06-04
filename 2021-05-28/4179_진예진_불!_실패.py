import sys
from queue import Queue


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bound(y, x):
    return 0 <= x < C and 0 <= y < R


def burn():
    global possible
    new_fire = Queue()
    while not fire.empty():
        f = fire.get()
        for d in range(4):
            ny = f['y'] + dy[d]
            nx = f['y'] + dx[d]

            if not bound(ny, nx):
                continue

            cur = maze[ny][nx]

            if cur == '.':
                cur = 'F'
                new_fire.put({'y': ny, 'x': nx})
    return new_fire


def escape_check(y, x):
    for d in range(4):
        ny = y + dy[d]
        nx = x + dx[d]

        if not bound(ny, nx):
            continue

        if maze[ny][nx] == '#':
            return True


## input

R, C = map(int, input().split())
maze = []
jihoon = Queue()
fire = Queue()
possible = 0

for r in range(R):
    temp = input()
    temp_list = []
    for c in range(C):
        temp_list.append(temp[c])
        if temp[c] == 'F':
            fire.put({'y': r, 'x': c})
        elif temp[c] == 'J':
            jihoon.put({'y': r, 'x': c, 'time': 0})

    maze.append(temp_list)

# print(maze)

while not jihoon.empty():
    fire = burn()
    if fire.empty(): # 지훈이가 나가지 못하는 경우 잘 생각해보기
        print('IMPOSSIBLE')
        exit(1)

    j = jihoon.get()
    # print(j, possible)
    for d in range(4):
        ny = j['y'] + dy[d]
        nx = j['x'] + dx[d]
        if not bound(ny, nx):
            if escape_check(j['y'], j['x']):
                print(j['time']+1) # 정답 출력
                exit(1)

        if (not bound(ny, nx)) or maze[ny][nx] == '#' or maze[ny][nx] == 'F':
            continue

        jihoon.put({'y': ny, 'x': nx, 'time': j['time'] + 1})
