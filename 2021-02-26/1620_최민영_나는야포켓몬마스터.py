import sys
# 안해줄시 시간초과
input = sys.stdin.readline
n, m = map(int, input().split())
cnt = 0
pocketmons = dict()
naming = dict()
# indexes = [""] * (n + 1)
for i in range(n):
    name = input().strip()
    pocketmons[name] = i + 1
    naming[i + 1] = name
    # indexes[i + 1] = name
for _ in range(m):
    q = input().strip()
    if q.isdigit() is True:
        print(naming[int(q)])
        # print(indexes[int(q)])
    else:
        print(pocketmons[q])
