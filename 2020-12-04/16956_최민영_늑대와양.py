import sys
input = sys.stdin.readline

# 3개의 반복문 이용하면 될 듯 -> 생각보다 간단한 문제
# 1. 처음부터 순차적으로 돌기
# 2. s의 부분을 만나면 상하좌우 돌면서 w가 있는지 확인
# 3-1. w가 없다면 d 넣기
# 3-2. w가 있다면 0 리턴

def solution():
    # dr = [-1, 1, 0, 0]
    # dc = [0, 0, -1, 1]
    move = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    r,c = map(int, input().split())
    farm = list()
    for _ in range(r):
        one_line = list(input()[:-1])
        farm.append(one_line)
    # print(farm)
    for i in range(r):
        for j in range(c):
            if farm[i][j] == "S":
                for mv in move:
                    mr = i + mv[0]
                    mc = j + mv[1]
                    if mr >= 0 and mr < r and mc >= 0 and mc < c:
                        if farm[mr][mc] == "W":
                            print(0)
                            return
                        if farm[mr][mc] == ".":
                            farm[mr][mc] = 'D'
    print(1)
    for row in farm:
        print("".join(row))
solution()
