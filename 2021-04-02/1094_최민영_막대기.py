import heapq
x = int(input())
cnt = 0
result = 64
sticks = [64]
while sum(sticks) > x:
    result = heapq.heappop(sticks)
    half = result // 2
    heapq.heappush(sticks, half)
    if sum(sticks) >= x:
       continue
    else:
        heapq.heappush(sticks, half)
print(len(sticks))
