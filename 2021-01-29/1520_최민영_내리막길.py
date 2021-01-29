import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
m, n = map(int, input().split())
way = [list(map(int, input().split())) for _ in range(m)]
dp = [[-1] * n for _ in range(m)]
# 북동남서 이동
mv = [(-1, 0), (0, 1), (1, 0), (0, -1)]
# 가장 마지막 부분을 넣음
# 가장 마지막 부분부터 역으로 타고 올라옴
def dfs_recur(i, j):
    # 맨 처음으로 갔을 경우
    if i == 0 and j == 0:
        return 1
    # 방문을 한번도 하지 않은 경우
    elif dp[i][j] == -1:
        dp[i][j] = 0
        for x, y in mv:
            n_i = i + x
            n_j = j + y
            if 0 <= n_i < m and 0 <= n_j < n and way[n_i][n_j] > way[i][j]:
                print(i, j)
                dp[i][j] += dfs_recur(n_i, n_j)
    # 방문 했던 경우는 값을 바로 리턴
    return dp[i][j]
# 거꾸로 채워가는 형태
print(dfs_recur(m-1, n-1))
for _ in dp:
    print(_)
