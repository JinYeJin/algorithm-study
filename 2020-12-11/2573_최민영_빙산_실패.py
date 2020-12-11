import sys
import heapq
from collections import deque
input = sys.stdin.readline

r,c = map(int, input().split())
iceberg = list()
for _ in range(r):
    iceberg.append(list(map(int, input().split())))

def solution(iceberg):
    dxdy = ((0, 1), (0, -1), (1, 0), (-1,0))
    result_count = 0
    # (value, i, j)
    heap_list = list()
    for i in range(r):
        for j in range(c):
            if iceberg[i][j] != 0:
                heapq.heappush(heap_list, (iceberg[i][j], i, j))
    # 경로를 탐색
    # 가장 작은 값을 뽑아서 그 값의 위치부터 시작 그 값보다 작은 값일 경우 count하지 않음

    def bfs(iceberg, visited, val, i, j):
        count = 0
        q = deque()
        q.append((val, i, j))
        while len(q) > 0:
            val, x, y = q.popleft()
            if visited[x][y] == 1:
                continue
            visited[x][y] = 1
            count += 1
            for dx, dy in dxdy:
                mx = x + dx
                my = y + dy
                if mx >= 0 and mx < r and my >= 0 and my < c:
                    if visited[mx][my] == 0 and iceberg[mx][my] >= val:
                        q.append((iceberg[mx][my], mx, my))
        return count
    while len(heap_list) > 0:
        pop_val, pop_i, pop_j = heapq.heappop(heap_list)
        visited = [[0 for _ in range(c)] for _ in range(r)]
        count_list = list()
        for i in range(r):
            for j in range(c):
                if iceberg[i][j] == pop_val and visited[i][j] == 0:
                    now_count = bfs(iceberg, visited, pop_val, pop_i, pop_j)
                    print("count", now_count)
                    count_list.append(now_count)
        print("count list", count_list)
        if len(count_list) > 0:
            result_count = pop_val
            break

    # print(heap_list)
    return result_count

result = solution(iceberg)
print(result)
