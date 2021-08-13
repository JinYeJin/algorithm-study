import sys
input = sys.stdin.readline
n, m = map(int, input().split())
table = [[float('inf')] * n for _ in range(n)]
dp = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j:
            table[i][j] = 0


for _ in range(m):
    a, b, c = map(int, input().split())
    table[a - 1][b - 1] = c
    table[b - 1][a - 1] = c
    dp[a - 1][b - 1] = b
    dp[b - 1][a - 1] = a

for _ in dp:
    print(_)
print()
for k in range(n):
    for i in range(n):
        for j in range(n):
            if table[i][k] + table[k][j] < table[i][j]:
                table[i][j] = table[i][k] + table[k][j]
                # 경유하는 곳을 적어줌
                dp[i][j] = dp[i][k]
                for _ in dp:
                    print(_)
                print()

for i in range(n):
    for j in range(n):
        if i == j:
            print("-", end=" ")
        else:
            print(dp[i][j], end=" ")
    print()
