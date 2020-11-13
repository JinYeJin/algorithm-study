n = int(input())
def solution(n):
    dp = [0 for i in range(1000001)]
    before = [0 for i in range(n+1)]
    i = 2
    while i <= n:
        dp[i] = dp[i-1] + 1
        before[i] = i - 1
        if i % 2 == 0:
            if dp[i] > dp[i//2] + 1:
                dp[i] = dp[i//2] + 1
                before[i] = i//2
        if i % 3 == 0:
            if dp[i] > dp[i//3] + 1:
                dp[i] = dp[i//3] + 1
                before[i] = i//3
        i += 1
    print(dp[n])
    print(n, end=" ")
    end = before[n]
    while end > 0:
        print(end, end=" ")
        end = before[end]
solution(n)
