import heapq

n = int(input())

array = []

for _ in range(n):
    heapq.heappush(array, int(input()))

answer = 0

while len(array) > 1:
    a = heapq.heappop(array)
    b = heapq.heappop(array)
    answer += a + b
    heapq.heappush(array, a + b)

print(answer)