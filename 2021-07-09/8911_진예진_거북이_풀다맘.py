import sys

sys.stdin = open("input/8911.txt")

N = int(input())

size = 1002

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

for i in range(N):
    map = [[False] * size for _ in range(size)]
    turtle = {'x': 500, 'y': 500, 'd': 0}
    commands = input()

    for command in commands:
        if command == 'F':
            nx = turtle['x'] + dx[turtle['d']]
            ny = turtle['y'] + dy[turtle['d']]
            map[ny][nx] = True
            turtle['x'] = nx
            turtle['y'] = ny
            print(ny, nx)
            print("F")
        elif command == 'B':
            nx = turtle['x'] + dx[(turtle['d']+2)%4]
            ny = turtle['y'] + dy[(turtle['d']+2)%4]
            map[ny][nx] = True
            turtle['x'] = nx
            turtle['y'] = ny
            print("B")
        elif command == 'L':
            temp = turtle['d'] - 1
            turtle['d'] = 3 if temp < 0 else temp
            print("L")
        elif command == 'R':
            turtle['d'] = (turtle['d'] + 1) % 4
            print("R")

    for i in range(490, 511):
        for j in range(490, 511):
            print(1 if map[i][j] else 0, end=" ")
        print()

    print("------------------")
