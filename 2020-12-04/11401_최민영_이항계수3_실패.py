import sys
from itertools import combinations


def solution():
    input = sys.stdin.readline

    n, k = map(int, input().split())
    num_list = [i for i in range(1, n+1)]
    result = len(list(combinations(num_list, k)))
    result = result % 1000000007
    return result

result = solution()
print(result)
