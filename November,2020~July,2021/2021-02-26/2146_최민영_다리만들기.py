# python 316ms / 400ms
from collections import deque
n = int(input())
con = [list(map(int, input().split())) for _ in range(n)]
mv = [(0, 1), (0, -1), (1, 0), (-1, 0)]
visited = [[False] * n for _ in range(n)]
# 대륙에 번호를 마킹하기 위한 지도
continent_number = [[-1] * n for _ in range(n)]
# 대륙의 숫자 카운팅
continent_cnt = 0
# 대륙의 번호 마킹
def check_continent(i, j):
    global continent_cnt
    global continent_number
    q = deque()
    q.append((i, j))
    visited[i][j] = True
    while q:
        a, b = q.popleft()
        # 현재 위치가 대륙의 끝부분인지 확인하기 위한 것
        c, inner = 0, 0
        for mx, my in mv:
            nx = a + mx
            ny = b + my
            if 0 <= nx < n and 0 <= ny < n:
                if con[nx][ny] == 1 and visited[nx][ny] is False:
                    visited[nx][ny] = True
                    q.append((nx, ny))
                inner += 1
                if con[nx][ny] == 1:
                    c += 1
        # 현재 끝부분이라면 대륙의 끝부분이라는 것을 의미하므로 번호 업데이트
        if c != inner:
            continent_number[a][b] = continent_cnt

continents = []

for i in range(n):
    for j in range(n):
        # 값이 1이라는 것은 대륙이라는 의미
        if con[i][j] == 1 and visited[i][j] is False:
            check_continent(i, j)
            # 새로운 대륙에서는 새로운 cnt 지정
            continent_cnt += 1

# 거리를 계산하기 위한 bfs
def bfs(i, j, c_index):
    global continents
    # 최소를 구하기 위해서 계속 방문 여부를 초기화 해주어야 함
    visited = [[False] * n for _ in range(n)]
    q = deque()
    q.append((i, j, 0))
    visited[i][j] = True
    while q:
        a, b, cnt = q.popleft()
        for mx, my in mv:
            nx = a + mx
            ny = b + my
            if 0 <= nx < n and 0 <= ny < n:
                # 0이라는 것은 바다를 지나는 중이라는 의미
                if con[nx][ny] == 0 and visited[nx][ny] is False:
                    visited[nx][ny] = True
                    q.append((nx, ny, cnt + 1))
                # 1이라는 것은 새로운 대륙이라는 의미
                if con[nx][ny] == 1 and continent_number[nx][ny] != c_index and continent_number[nx][ny] != -1:
                    return cnt
    return n * n
result = n * n
for i in range(n):
    for j in range(n):
        # 대륙의 끝부분일경우 bfs수행
        if continent_number[i][j] != -1:
            result = min(result, bfs(i, j, continent_number[i][j]))
print(result)