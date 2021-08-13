import sys
from collections import deque
import copy
input = sys.stdin.readline
# 처음 설명했던것은 0이 맞닿은 부분은 더 빨리 줄어드는 것을 고려하지 않은 코드
# 로직
# 반복문과 bfs 사용
# 1. 반복문 탈출 조건
#     1-1. bfs와 반복문을 이용해서 탐색 가능한 경로의 갯수가 1 이상일 경우 break
#     1-2. 전체가 0이 되어버리는 경우
#             - 이 경우는 나눠지는 경우가 아닌 모두가 0이 되어버리는 경우를 뜻함
# 2. 반복문을 이용하여 해가 지날때마다 빙산을 업데이트
# 3. 업데이트된 빙산이 모두 0이 되는지 확인
#     - 0 이 아닐 경우 다시 반복

iceberg_map = list()
r, c = map(int, input().split())
for _ in range(r):
    iceberg_map.append(list(map(int, input().split())))
dxdy = ((0, 1), (0, -1), (1, 0), (-1, 0))


def solution():
    year = 0
    check_all_zero = False
    while check_all_zero is False:
        visited = [[0 for _ in range(c)] for _ in range(r)]
        count_list = list()

        for i in range(r):
            for j in range(c):
                if visited[i][j] == 0 and iceberg_map[i][j] > 0:
                    count_loop = bfs(visited, i, j)
                    count_list.append(count_loop)

        if len(count_list) > 1:
            break
        update_iceberg()

        # 전체가 0일때 break
        check_all_zero = check_zero()
        year += 1
    if check_all_zero:
        return 0
    return year


def update_iceberg():
    before_iceberg_map = copy.deepcopy(iceberg_map)

    for i in range(r):
        for j in range(c):
            if before_iceberg_map[i][j] > 0:
                del_count = 0
                for dx, dy in dxdy:
                    mx = dx + i
                    my = dy + j
                    if before_iceberg_map[mx][my] == 0:
                        del_count += 1
                iceberg_map[i][j] -= del_count
                if iceberg_map[i][j] < 0:
                    iceberg_map[i][j] = 0


def check_zero():
    zero_count = 0
    for i in range(r):
        for j in range(c):
            if iceberg_map[i][j] == 0:
                zero_count += 1
    if zero_count == r * c:
        return True
    return False


def bfs(visited, i, j):
    count = 0
    q = deque()
    q.append((i, j))
    while len(q) > 0:
        x, y = q.popleft()
        if visited[x][y] == 1:
            continue
        visited[x][y] = 1
        count += 1
        for dx, dy in dxdy:
            mx = x + dx
            my = y + dy
            if 0 <= mx < r and 0 <= my < c:
                if visited[mx][my] == 0 and iceberg_map[mx][my] > 0:
                    q.append((mx, my))
    return count


result = solution()
print(result)
