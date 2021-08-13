import sys
from queue import Queue

sys.stdin = open("input/5014.txt")

F, S, G, U, D = map(int, input().split())

dp = [987654321] * (F+1)

floor = Queue()
floor.put(S)

dp[S] = 0

while(not floor.empty()):
    current = floor.get()

    # boundary
    if current > F or current < 1:
        continue

    # answer
    if current == G:
        break
    # print(current)
    # print(dp)

    # UP
    if current + U <= F:
        if (dp[current] + 1) < dp[current + U]:
            dp[current + U] = dp[current] + 1
            floor.put(current + U)

    # Down
    if current - D > 0:
        if (dp[current] + 1) < dp[current - D]:
            dp[current - D] = dp[current] + 1
            floor.put(current - D)


if dp[G] == 987654321:
    print("use the stairs")
else:
    print(dp[G])
