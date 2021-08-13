# -*- coding: utf-8 -*-

# 트리의 지름
# 시간 : 2시간
# 구현 아이디어 : dfs -> node마다의 지름의 크기가 다르기 때문에 node를 하나씩을 방문하면서 최대길이를 dfs로 구하는 방식
# 1) 1번 노드에서 n번 노드까지 for문을 타면서 dfs 수행
# 2) i번 노드에서 다음 노드로 갈 때마다 횟수와 가중치를 더해주기
# 3) 연결된 모든 리프노드를 방문하기 위해서 for문을 한 번 더 수행
# 4) dfs로 깊이가 가장 깊은 노드에 도착했을 때 ans에 지름이 최대일 떄의 가중치의 최대값을 갱신
# 5) dfs의 끝 값에서의 값에 해당하는 가중치를 빼주고 리턴

import sys
input = sys.stdin.readline
n = int(input())
g = [[] for _ in range(n + 1)]
ans = [0, 0] # 가장 높은 지름, 가중치
d = 0 # 한 지점에서의 트리의 지름
c = 0 # 그때의 가중치
for _ in range(n):
    line = list(map(int, input().split()))
    s = line[0]
    for j in range(1, len(line) - 1, 2):
        e, w = line[j], line[j + 1]
        g[s].append([e, w])
def dfs(i, j, start):
    if i > n:
        return
    if visited[i]:
        return
    global d, c
    visited[i] = 1
    for j in range(j, len(g[i])):
        # 양방향 그래프이기 때문에 이미 방문한 양방향 노드는 패스
        if g[i][j][0] == start:
            continue
        # i를 기준으로 j + 1 번째로 연결된 노드에서 가중치와 횟수를 더함
        if not visited[g[i][j][0]]:
            d += 1
            c += g[i][j][1]
            dfs(g[i][j][0], 0, start)
    # 가장 깊은 노드에 도착했을 때 ans에 저장된 값과 비교해서 지름이 더 작으면 갱신
    # 지름이 같으면 가중치의 합이 더 큰 값을 저장
    if ans[0] <= d:
        if ans[0] == d and ans[1] >= c:
            {}
        else:
            ans[0], ans[1] = d, c
    # 가장 깊은 곳에서 다시 값을 빼주고 for문으로 다시 리턴
    d -= 1
    c -= g[i][j][1]

for i in range(1, n + 1):
    visited = [0] * (n + 1)
    d, c, j = 0, 0, 0
    dfs(i, j, i)
print(ans[1])

# 4
# 1 2 5 3 9 -1
# 2 1 5 -1
# 3 1 9 4 8 -1
# 4 3 8 -1