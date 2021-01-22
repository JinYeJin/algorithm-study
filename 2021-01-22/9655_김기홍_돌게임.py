n = int(input())

d = [float('inf')] * (n + 1)
move = [1, 3]

q = [(0, 0)]
d[0] = 0
while q:
    now, cnt = q.pop(0)
    for m in move:
        next = now + m
        if next <= n and d[next] == float("inf"):
            d[next] = cnt + 1
            q.append((next, cnt + 1))

if d[n] % 2 == 0:
    print("CY")
else:
    print("SK")


