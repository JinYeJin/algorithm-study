import sys
sys.stdin = open("input/14503.txt")

def boundary(x, y):
    return 0 <= x < N and 0 <= y < M

dx = [-1,0,1,0]
dy = [0,1,0,-1]

N, M = map(int, input().split())
R, C, D = map(int, input().split())

cleaned = []
for i in range(N):
    cleaned.append(list(map(int, input().split())))

num_clean = 1
x, y = R, C
cleaned[x][y] = 2

while True:
    revers_check = True

    # 4 방위 체크
    for i in range(4):
        D = (D-1) % 4 # 왼쪽 회전
        nx = x + dx[D]
        ny = y + dy[D]

        if not boundary(nx, ny):
            continue

        if cleaned[nx][ny] == 0:
            num_clean += 1
            cleaned[nx][ny] = 2
            x, y = nx, ny
            revers_check = False
            break

    if revers_check: # 4방향 중 하나도 갈 곳이 없었던 경우
        nx = x - dx[D]
        ny = y - dy[D]

        if boundary(nx, ny):
            if cleaned[nx][ny] == 2:  # 2:청소한 칸
                x, y = nx, ny
            elif cleaned[nx][ny] == 1:  # 1: 벽 칸
                print(num_clean)
                break
        else:
            print(num_clean)
            break
