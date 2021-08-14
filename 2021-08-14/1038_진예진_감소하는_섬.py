import sys
sys.stdin = open("input/1038.txt")

N = int(input())

number = [0] * 10
dp = [[None] * 10 for _ in range(10)]

def dfs(digit, limit, order):
    global N
    # if dp[digit][limit] != None:
    #     N -= dp[digit][limit]
    #     return
    # print("dfs(%d,%d) "%(digit, limit))
    order += "dfs(%d,%d) => "%(digit, limit)
    if digit < 0:
        print(order + "return")
        # print("return")
        return True
    print(order)
    # print("dfs(%d,%d) "%(digit, limit))
    # dfs(digit - 1, limit, order)
    if N < 0: return

    l = digit

    while(l < limit < 10):
    # for l in range(digit, limit):
        number[digit] = l
        N -= 1
        limit += dfs(digit-1, l, order)
        # dp[digit][limit] = N
        # print(order)
        print("In dfs(%d,%d),"%(digit, limit), "l: %d,"%l, number)
        l += 1
    print()

dfs(9, 1, "")

print(
