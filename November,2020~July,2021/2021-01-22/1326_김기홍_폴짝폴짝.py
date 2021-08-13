from collections import deque

n = int(input())

bridge = [0] + list(map(int, input().split()))

a, b = map(int, input().split())

answer = 0

q = deque()
d = [10001] * (n + 1)


q.append((a, 0))
d[a] = 1
while q:
    print(q)
    now, cnt = q.popleft()
    for i in range(now + bridge[now], n + 1, bridge[now]):
        if d[i] == 10001:
            d[i] = cnt + 1
            q.append((i, cnt + 1))
    for i in range(now - bridge[now], 0, -bridge[now]):
        if d[i] == 10001:
            d[i] = cnt + 1
            q.append((i, cnt + 1))

if d[b] == 10001:
    print(-1)
else:
    print(d[b])

print(d)
