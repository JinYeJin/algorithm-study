import heapq
import sys
input = sys.stdin.readline
n = int(input())
nums = list()
for _ in range(n):
    heapq.heappush(nums, int(input()))
if len(nums) == 1:
    print(0)
    exit(0)
sum = 0
# 최소로 만드는 경우는 가장 작은 2 값을 뽑아서 넣고, 다시 가장 작은 2값을 더해서 넣는 방식으로
# 가장 작은 것들 만을 계속 찾아서 더해가는 방식
while nums:
    if len(nums) >= 2:
        # 가장 작은 2개를 뽑아서 더함
        # 더한 값을 다시 넣음
        a = heapq.heappop(nums)
        b = heapq.heappop(nums)
        sum += a + b
        heapq.heappush(nums, a + b)
    else:
        break
print(sum)
