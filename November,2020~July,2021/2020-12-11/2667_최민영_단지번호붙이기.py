# * bfs 이용하여 풀이
# 1. 입력 받음
# 2. 이중 for문을 이용하여 방문하지 않은 곳만 bfs연산
# 3. 방문한 곳은 1로 처리하여 재방문 하지 않음
# 4. bfs가 종료되면 결과 카운트 리스트에 추가
# 5. 결과 카운트 리스트 출력
import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
apartment_map = list()
for _ in range(n):
    apartment_map.append(list(map(int, input().strip())))

def solution(n, aprt_map):
    dxdy = ((0, 1), (0, -1), (1, 0), (-1,0))
    visited = [[0 for _ in range(n)] for _ in range(n)]
    result_count = list()
    def bfs(i, j):
        q = deque()
        q.append((i, j))
        count = 0
        while len(q) > 0:
            x,y = q.popleft()
            if visited[x][y] != 0:
                continue
            visited[x][y] = 1
            count += 1
            for dx, dy in dxdy:
                mx = x + dx
                my = y + dy
                if mx >= 0 and mx < n and my >= 0 and my < n:
                    if visited[mx][my] == 0 and aprt_map[mx][my] == 1:
                        q.append((mx, my))
        return count
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0 and aprt_map[i][j] == 1:
                loop = bfs(i,j)
                result_count.append(loop)
    return result_count
result = solution(n, apartment_map)
print(len(result))
for _ in sorted(result):
    print(_)
