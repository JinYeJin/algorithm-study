# 정제헌을 팔자!
# 구현 아이디어 : n ** 2의 n까지의 약수의 개수를 구하기

import sys
input = sys.stdin.readline

def solution():
    while 1:
        arr = list(map(str, input()))
        tmp = "".join(map(str, arr[2:]))
        n = int(tmp)
        cnt = 0
        for i in range(1, n + 1):
            if n ** 2 % i == 0:
                cnt += 1
        print(cnt)
solution()