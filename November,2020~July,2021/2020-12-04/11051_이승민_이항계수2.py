# 이항 계수 2
import math
n, k = map(int, input().split())
dp = [0] + [1] * 1010

# 기존 코드 - 중간 값 오버플로우로 안 되는 것이 아니라?
# '/' -> float 오차발생할 수 있음 //  '//' -> int 오차 x
def fact(n):
    if n == k or k == 0:
        print(1)
        return
    if n < k:
        print(0)
        return
    
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] * i 
    print(dp[n] // (dp[n-k] * dp[k]) % 10007)   
fact(n)
