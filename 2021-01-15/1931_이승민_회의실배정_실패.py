# 회의실배정
import sys
from bisect import bisect_left as bl
input = sys.stdin.readline
n = int(input())
for
arr = [list(map(int, input().split())) for _ in range(n)]
arr.sort()

def solution():
    ans = 0
    for i in range(n - 1):
        cnt = 1
        tmp = arr[i][1]
        for j in range(n):
            tmp2 = bl(arr, tmp)
            tmp = arr[tmp2][1]
            cnt += 1
        ans = max(ans, cnt)
    print(ans)
solution()