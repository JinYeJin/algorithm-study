# -*- coding: utf-8 -*-

# 문자열폭발
import sys
from collections import deque
input = sys.stdin.readline
s = input().strip()
bomb = input().strip()
l = len(bomb)
while 1:
    i, j = 0, 0
    check = 0
    tmp = ""
    while i < len(s) - l + 1:
        if bomb == s[i : i + l]:
            i += l
            check = 1
        else:
            tmp += s[i]
            i += 1
    if tmp == "":
        print("FRULA")
        quit(0)
    if not check:
        print(tmp)
        quit(0)
    s = tmp

            

