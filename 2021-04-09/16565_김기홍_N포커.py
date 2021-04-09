n = int(input())

dp = [[0] * 53 for i in range(53)]


for i in range(53):
    dp[i][0] = 1
    dp[i][i] = 1
    for j in range(1, i):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007

answer = 0

for i in range(4, n + 1, 4):
    if (i // 4) % 2 == 1:
        answer += dp[13][i//4] * dp[52 - i][n - i]
    else:
        answer -= dp[13][i//4] * dp[52 - i][n - i]
    answer %= 10007

if answer < 0:
    answer += 10007

print(answer)