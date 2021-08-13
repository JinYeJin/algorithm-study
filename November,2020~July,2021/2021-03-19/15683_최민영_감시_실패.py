import sys
import copy
input = sys.stdin.readline
# 4가지
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
# 2가지
two = [(0, 2), (1, 3)]
# 4가지
three = [(3, 0), (0, 1), (2, 1), (2, 3)]
# 4가지
four = [(2, 3, 0), (3, 0, 1), (2, 0, 1), (1, 2, 3)]
# 1가지
five = (0, 1, 2, 3)
n, m = map(int, input().split())
office_init = []
office = []
office_map = []
total_cnt = 1
for _ in range(n):
    l = list(map(int, input().split()))
    office.append(l)
    t = [0] * len(l)
    for i in range(len(l)):
        if 1 <= l[i] <= 5:
            if l[i] == 1:
                t[i] = [l[i], 3]
                total_cnt *= 4
            elif l[i] == 2:
                t[i] = [l[i], 1]
                total_cnt *= 2
            elif l[i] == 3:
                t[i] = [l[i], 3]
                total_cnt *= 4
            elif l[i] == 4:
                t[i] = [l[i], 3]
                total_cnt *= 4
            elif l[i] == 5:
                t[i] = [l[i], 0]
        else:
            t[i] = l[i]
    office_map.append(t)
office_init = copy.deepcopy(office)

# for i in office:
#     print(i)
# print()
# for i in office_map:
#     print(i)
# print("시작")
result = m * n
blind_spot_max = m * n

def goOne(i, j, idx):
    nx, ny = i + dir[idx][0], j + dir[idx][1]
    while 0 <= nx < n and 0 <= ny < m and office[nx][ny] != 6:
        office[nx][ny] = -1
        nx += dir[idx][0]
        ny += dir[idx][1]

def goTwo(i, j, idx):
    for d in two[idx]:
        goOne(i, j, d)

def goThree(i, j, idx):
    for d in three[idx]:
        goOne(i, j, d)

def goFour(i, j, idx):
    for d in four[idx]:
        goOne(i, j, d)

def goFive(i, j, idx):
    for d in five:
        goOne(i, j, d)



while total_cnt > 0:
    cnt = 0
    for i in range(n):
        for j in range(m):
            if 1 <= office[i][j] < 6:
                if office_map[i][j][1] > -1:
                    for k in range(ma)
                    if office[i][j] == 1:
                        goOne(i, j, office_map[i][j][1])
                        office_map[i][j][1] -= 1
                    elif office[i][j] == 2:
                        goTwo(i, j, office_map[i][j][1])
                        office_map[i][j][1] -= 1
                    elif office[i][j] == 3:
                        goThree(i, j, office_map[i][j][1])
                        office_map[i][j][1] -= 1
                    elif office[i][j] == 4:
                        goFour(i, j, office_map[i][j][1])
                        office_map[i][j][1] -= 1
                    elif office[i][j] == 5:
                        goFive(i, j, office_map[i][j][1])
                        office_map[i][j][1] -= 1
    total_cnt -= 1
    for i in office:
        print(i)
    print("종료")
    for i in range(n):
        for j in range(m):
            if office[i][j] != 0:
                cnt += 1
    blind_spot = blind_spot_max - cnt
    result = min(result, blind_spot)
    office = copy.deepcopy(office_init)

print(result)

# print(office)

