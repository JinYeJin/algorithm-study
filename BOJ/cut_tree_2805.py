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
