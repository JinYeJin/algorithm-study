# dfs, dp

def dfs(x, y):
    if dp[x][y]:
        return dp[x][y]

    if x == 0:
        return 1

    dp[x][y] = dfs(x - 1, y + 1)

    if y > 0:
        dp[x][y] += dfs(x, y - 1)

    return dp[x][y]


while True:
    n = int(input())

    if n == 0:
        break

    dp = [[0] * 31 for _ in range(31)]
    print(dfs(n, 0))


# df

# dp = [[0] * 31 for _ in range(31)]
# for j in range(31):
#     dp[0][j] = 1
# for i in range(31):
#     for j in range(1, 31):
#         dp[i][j]=dp[i-1][j]+dp[i][j-1]


# while True:
#     n = int(input())

#     if n == 0:
#         break
#     else:
#         print(dp[n][n])
