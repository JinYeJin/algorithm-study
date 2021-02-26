n, m = map(int, input().split())

d = {}

num = 1
for _ in range(n):
    key = input()
    d[key] = num
    d[num] = key
    num += 1

for _ in range(m):
    target = input()
    if target.isalpha():
        print(d[target])
    else:
        print(d[int(target)])

