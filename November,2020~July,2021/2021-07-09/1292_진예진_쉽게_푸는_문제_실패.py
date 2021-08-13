import sys
sys.stdin = open("input/1292.txt")

import math

A, B = map(int, input().split())
numbers = []

for i in range(round(B/2)):
    for j in range(i):
        numbers.append(i)

# print(len(numbers))
# print(numbers)
# print(numbers[A-1:B])
print(sum(numbers[A-1:B]))
