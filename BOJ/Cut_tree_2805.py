from sys import stdin
N, M = map(int, input().split())
trees = [ int(i) for i in stdin.readline().split() ]
trees.sort(reverse=True)
high = max(trees) #나무가 많은 경우 그냥 제한높이 값을 넣는게 나을것인가?
low = 0

while low<=high:
	cut_height = (low + high)//2
	sum = 0
	for i in range(N):
		if trees[i] >= cut_height:
		    sum += trees[i] - cut_height
		
		if sum >= M:
			break
	
	if sum >= M:		
		low = cut_height + 1
	else: #sum < M
		high = cut_height - 1		

print(high)



'''
# 다른이의 방법 Counter 사용으로 시간 단축!

import sys
from collections import Counter

N, M = map(int, sys.stdin.readline().split())
li = Counter(map(int, sys.stdin.readline().split()))
high, low = max(li), 1

while high >= low:
    mid = (high + low) // 2
    res = sum((t - mid) * c  if t > mid else 0 for t, c in li.items())
    if res >= M:
        ans = mid
        low = mid + 1
    else:
        high = mid - 1
try:
    print(ans)
except:
    print(high)

'''