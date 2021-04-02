import sys
input = sys.stdin.readline
n, k = map(int, input().split())
wv = []
for _ in range(n):
    w, v = map(int, input().split())
    wv.append((w, v))

dp = [[0] * (k + 1) for _ in range(n + 1)]
for i in range(n + 1):
    for j in range(k + 1):
        if j < wv[i - 1][0]:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wv[i - 1][0]] + wv[i - 1][1])
print(dp[n - 1][k])
