#sick knight 1783
from sys import stdin

N, M = map(int, stdin.readline().split())
if N == 1:
    print(1)
elif N == 2:
    print(min(4, (M + 1) // 2))
elif M < 7:
    print(min(4, M))
else:
    print(M - 7 + 5)


#https://dirmathfl.tistory.com/223