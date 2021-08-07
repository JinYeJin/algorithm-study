global cnt
cnt = 0

def l_rotate(distance, dx, dy):
    dx = dx[distance:]  + dx[:distance]
    dy = dy[distance:]  + dy[:distance]

    return dx, dy

def clean(location, direc, rec):
    global cnt
    #print(f"clean method start location: {location}")
    r, c = location    
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    dx, dy = l_rotate(d, dx, dy)

    rec[r][c] = 2
    cnt += 1
    for i in range(4):
        x = r + dx[i]
        y = c + dy[i]
        #print(f"{x}, {y}")
        if rec[x][y] == 0:
            return clean((x, y), direc, rec)
    r_x = r - dx[-1]
    r_y = c - dy[-1]
    #print(f"r_x, r_y: {r_x}, {r_y}")
    #print(f"{rec[r_x][r_y]=}")
    if rec[r_x][r_y] == 2:
        return clean((r_x, r_y), direc, rec)
    return 


n, m = map(int, input().split())
r, c, d = map(int, input().split())
rectangle = []
for _ in range(n):
    rectangle.append(list(map(int, input().split())))

location = (r, c)
clean(location, d, rectangle)
print(cnt)


'''
1. 현재 위치를 청소
2. 현재 위치에서 현재 방향을 기준으로왼족 방향부터 차례대로 인접 칸 탐색
    a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 
        그 방향으로 회전한 다음 한 칸 전진하고 1번부터 진행
    b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    c. 네 방향 모두 청소가 이미 되어이썩나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

이미 청소되어 있는 칸을 다시 청소하지 않으며 벽은 통과할 수 없다.

이미 청소한 칸은 2로 바꾼다.
'''

