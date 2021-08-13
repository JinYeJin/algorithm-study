from queue import Queue


def bfs(x, y, flag):
    q = Queue()
    temp_arr = [[0]*6 for _ in range(12)]
    q.put([x, y])
    cnt = 1
    temp_arr[x][y] = cnt
    while not q.empty():
        x, y = q.get()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6:
                if arr[nx][ny] == arr[x][y] and temp_arr[nx][ny] == 0:
                    cnt += 1
                    temp_arr[nx][ny] = 1
                    q.put([nx, ny])

    # 4개 이상이 모이면 터짐
    if cnt >= 4:
        flag += 1
        for i in range(12):
            for j in range(6):
                if temp_arr[i][j] == 1:
                    arr[i][j] = '.'
    return flag


def down():
    for c in range(6):
        temp = Queue()
        for r in range(11, -1, -1):
            if arr[r][c] != '.':
                temp.put(arr[r][c])
        for r in range(11, -1, -1):
            if not temp.empty():
                arr[r][c] = temp.get()
            else:
                arr[r][c] = '.'


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

arr = [0] * 12

for i in range(12):
    temp = input()
    arr[i] = list(temp)

ans = 0
while True:
    cnt = 0
    for r in range(12):
        for c in range(6):
            if arr[r][c] != '.':
                cnt = bfs(r, c, cnt)
    if cnt == 0:
        print(ans)
        break
    else:
        ans += 1
    down()
