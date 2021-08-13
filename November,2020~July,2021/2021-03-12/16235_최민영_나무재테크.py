n, m, k = map(int, input().split())
energy = []
trees = [[[]] * n for _ in range(n)]
dead_trees = [[[]] * n for _ in range(n)]
init_val = [[5] * n for _ in range(n)]
for _ in range(n):
    energy.append(list(map(int, input().split())))
for _ in range(m):
    x, y, year = map(int, input().split())
    if len(trees[x - 1][y - 1]) == 0:
        trees[x - 1][y - 1] = [year]
    else:
        trees[x - 1][y - 1].append(year)
# 3차원 배열
# print(trees)
near = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
# for _ in trees:
#     print(_)

# 양분을 먹은만큼 양분도 줄여줘야 함
def spring():
    for i in range(n):
        for j in range(n):
            trees[i][j].sort()
            # 양분먼저 먹고 나이 추가
            t = -1
            for k in range(len(trees[i][j])):
                if trees[i][j][k] <= init_val[i][j]:
                    init_val[i][j] -= trees[i][j][k]
                    trees[i][j][k] += 1
                elif trees[i][j][k] > init_val[i][j]:
                    t = k
                    break
            if t != -1:
                while len(trees[i][j]) > t:
                    # print("trees[i][j][-1]", trees[i][j][-1])
                    if len(dead_trees[i][j]) == 0:
                        dead_trees[i][j] = [trees[i][j][-1]]
                    else:
                        dead_trees[i][j].append(trees[i][j][-1])
                    trees[i][j].pop()

def summer():
    for i in range(n):
        for j in range(n):
            for dt in range(len(dead_trees[i][j])):
                if len(dead_trees[i][j]) != 0:
                    init_val[i][j] += (dead_trees[i][j][dt] // 2)
            while len(dead_trees[i][j]) > 0:
                dead_trees[i][j].pop()

def fall():
    for i in range(n):
        for j in range(n):
            ni, nj = 0, 0
            for mx, my in near:
                ni = i + mx
                nj = j + my
                if 0 <= ni < n and 0 <= nj < n:
                    for k in range(len(trees[i][j])):
                        if trees[i][j][k] % 5 == 0:
                            if len(trees[ni][nj]) == 0:
                                trees[ni][nj] = [1]
                            else:
                                trees[ni][nj].append(1)

def winter():
    for i in range(n):
        for j in range(n):
            init_val[i][j] += energy[i][j]

for yy in range(k):
    spring()
    summer()
    fall()
    winter()
total = 0
for a in range(n):
    for b in range(n):
        total += len(trees[a][b])
# for i in trees:
#     print(i)
print(total)

