import copy
from collections import deque
n, l, r = map(int, input().split())
population = []
check_map = [[0] * n for _ in range(n)]
for _ in range(n):
    population.append(map(int, input().split()))
mv_cnt = 0
init_po = copy.deepcopy(population)
visited = [[False] * n for _ in range(n)]

mv = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def check_population(x, y, idx):
    q = deque([(x, y)])
    visited[x][y] = True
    check_map[x][y] = idx
    sum = population[x][y]
    cnt = 1
    while q:
        nowX, nowY = q.popleft()
        # if visited[nowX][nowY] is True:
        for mx, my in mv:
            nx = nowX + mx
            ny = nowY + my
            if 0 <= nx < n and 0 <= ny < n and l <= abs(population[nowX][nowY] - population[nx][ny]) <= r and visited[nx][ny] is False:
                check_map[nx][ny] = idx
                visited[nx][ny] = True
                sum += population[x][y]
                cnt += 1
                q.append((nx, ny))

def update_population(x, y):

while True:
    if population == init_po:
        print(mv_cnt)
        break
    idx = 0
    # 전체 체크
    for i in range(n):
        for j in range(n):
            if visited[i][j] is False:
                idx += 1
                check_population(i, j, idx)
    # 업데이트
