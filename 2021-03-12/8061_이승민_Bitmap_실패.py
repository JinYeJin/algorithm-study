# -*- coding: utf-8 -*-

# Bitmap
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(map(int, list(map(int, input().strip())))) for _ in range(n)]
for i in range(n):
    tmp = 1
    for j in range(m - 1, -1, -1):
        if arr[i][j] == 1:
            arr[i][j] = 0
            tmp = 1
        else:
            arr[i][j] = tmp
            tmp += 1
for i in range(n):
    print(" ".join(map(str, arr[i])))
