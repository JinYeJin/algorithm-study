import heapq

n = int(input())

works = []
days = 0
for _ in range(n):
    day, value = map(int, input().split())
    days = max(days, day)
    works.append((-value, day))

heapq.heapify(works)
check = [0] * (days + 1)

while works:
    value, day = heapq.heappop(works)
    for i in range(day, 0, -1):
        if check[i] == 0:
            check[i] = -value
            break

print(sum(check))
