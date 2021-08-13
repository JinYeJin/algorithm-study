# 1
import sys
sys.setrecursionlimit(100000)
def solution():
    n, k = map(int, input().split())
    dp = [[0 for _ in range(1001)] for _ in range(1001)]
    def bino(n, k):
        if k == 0 or n == k:
            return 1
        if dp[n][k] == 0:
            dp[n][k] = bino(n - 1, k) % 10007 + bino(n - 1, k - 1) % 10007
        return dp[n][k]

    result = bino(n,k) % 10007
    return result

result = solution()
print(result)

# 2
def solution():
    n, k = map(int, input().split())
    dp = [[0 for _ in range(1001)] for _ in range(1001)]
    for i in range(n+1):
        dp[i][0] = 1
    for j in range(k+1):
        dp[j][j] = 1

    for i in range(1, n+1):
        for j in range(1, k+1):
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007
    return dp[n][k]

result = solution()
print(result)
