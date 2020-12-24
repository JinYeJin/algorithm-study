# 페르마의 크리스마스 정리
# 구현 아이디어 : 에라토스테네스의 체로 n ** 0.5 + 1까지의 소수를 구하고 bisect으로 l, u 범위에 해당하는 소수를 구하고
# 배열의 길이를 cnt1 에 저장, 그 중 에서 4로 나눈 나머지가 1인 친구들 cnt2에 더하기

import sys
from bisect import bisect_left as bl
from bisect import bisect_right as br
input = sys.stdin.readline

def primeNum():
    pn = [False, False, True] + [True, False] * 500000 # Prime Number
    for i in range(3, 1001, 2):
        if pn[i]:
            pn[i * 2 :: i] = len(pn[i * 2 :: i]) * [False]
    return [i for i in range(1000001) if pn[i]]

def solution(pNum):
    s = ""
    while 1:
        cnt1 = 0
        cnt2 = 0
        l, u = map(int, input().split())
        if l == u == -1: break
        if l <= 0: l = 0
        if u <= 0: u = 0
        ans = pNum[bl(pNum, l) : br(pNum, u)]
        cnt1 = len(ans)
        for i in ans:
            if i % 4 == 1:
                cnt2 += 1
        if l <= 2 and u >= 2: cnt2 += 1
        s += str(l) + " " + str(u) + " " + str(cnt1) + " " + str(cnt2) + "\n"
    print(s)
pNum = primeNum()
solution(pNum)



# def squareSumNum(n):
#     for j in range(math.ceil(math.sqrt(n))):
#         for k in range(math.ceil(math.sqrt(n))):
#             if j ** 2 + k ** 2 == n:
#                 return True