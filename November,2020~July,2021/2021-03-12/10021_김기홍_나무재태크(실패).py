n, m, k = map(int, input().split())

dx = [0, 0, -1, 1, -1, -1, 1, 1]
dy = [-1, 1, 0, 0, -1, 1, -1, 1]

board = [[5] * n for _ in range(n)]
A = []
tree = {}
dead = []
new = []

for _ in range(n):
    A.append(list(map(int, input().split())))

for _ in range(m):
    x, y, z = map(int, input().split())
    tree[(x - 1, y - 1)] = [z]

while k:
    # 봄
    for pos, age in tree.items():
        x, y = pos
        age.sort()
        for i in range(len(age)):
            if board[x][y] - age[i] >= 0:
                board[x][y] -= age[i]
                age[i] += 1
            else:
                dead.append((x, y, i))

    # 여름
    while dead:
        x, y, idx = dead.pop()
        board[x][y] += tree[(x, y)][idx] // 2
        del tree[(x, y)][idx]

    # 가을
    for pos, age in tree.items():
        x, y = pos
        for i in range(len(age)):
            if age[i] % 5 == 0:
                for j in range(8):
                    nx = x + dx[j]
                    ny = y + dy[j]
                    if nx >= 0 and nx <= n and ny >= 0 and ny <= m:
                        new.append((nx, ny))
    while new:
        x, y = new.pop()
        if (x, y) in tree.keys():
            tree[(x, y)].append(1)
        else:
            tree[(x, y)] = [1]

    # 겨울
    for i in range(n):
        for j in range(n):
            board[i][j] += A[i][j]
    k -= 1

answer = 0

for key, value in tree.items():
    answer += len(value)

print(answer)
