import sys
input = sys.stdin.readline
n = int(input())
rope = [int(input()) for i in range(n)]
# print(rope)
rope.sort(reverse=True)
# print(rope)
weight = 0
for i in range(len(rope)):
    weight = max(weight, rope[i] * (i + 1))
print(weight)
