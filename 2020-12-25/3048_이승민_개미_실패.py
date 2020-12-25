# 개미
import sys

input = sys.stdin.readline
n1, n2 = map(int, input().split())
a1 = list(map(str, input().strip()))[:: -1]
a2 = list(map(str, input().strip()))
n = int(input())
a3 = a1 + a2
for i in range(1, n + 1):
    cnt = 0
    for j in range(len(a3) - 1):
        if a3[j] in a1 and a3[j + 1] not in a1:
            tmp = a3[j]
            a3[j] = a3[j + 1]
            a3[j + 1] = tmp
            cnt += 1
        if cnt == i:
            break
print("".join(list(map(str, a3))))