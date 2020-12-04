import sys
from math import factorial

input = sys.stdin.readline
n, k = map(int, input().split())
nck = factorial(n)//(factorial(n-k)*factorial(k))
print(nck%10007)
