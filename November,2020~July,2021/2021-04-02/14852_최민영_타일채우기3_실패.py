n = int(input())
if n == 0:
    print(0)
    exit(0)
dp = [0] * (n + 1)
dp[1] = 2
for i in range(2, n + 1):
    dp[i] += dp[i - 1] + 2
    # if i >= 2:
    if i % 2 == 0:
        dp[i] += dp[i - 2] + 7
    dp[i] = dp[i] % 1000000007

print(dp[n])
