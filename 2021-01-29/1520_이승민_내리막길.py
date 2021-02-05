# 내리막 길
# 시간 : 5시간 반
# 구현 아이디어 : 처음에는 bfs로 생각했지만 깊이 우선탐색으로 생각을 바꿨습니다. 
# 이유는 최대 깊이를 구하는 방식인 것같아서 속도가 더 빠를 것 같아서
# 이전 지점 (i, j) 에 다음 지점 (ii, jj)에서 (n, m)에 도달하기까지 해당 위치의 사용횟수를 증가

import sys
input = sys.stdin.readline
n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(m)] for _ in range(n)]
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]

def dfs(i, j):
    # n, m 에 도달했을 때
    if i + 1 == n and j + 1 == m:
        return 1
    if dp[i][j] != 0:
        return dp[i][j]
    for k in range(4):
        ii = di[k] + i
        jj = dj[k] + j
        if 0 <= ii < n and 0 <= jj < m and g[i][j] > g[ii][jj]:
            dp[i][j] += dfs(ii, jj)
    return dp[i][j]
print(dfs(0, 0))

# Test Case
# 4 4
# 16 9 8 1
# 15 10 7 2
# 14 11 6 3
# 13 12 5 4
# 답 : 10