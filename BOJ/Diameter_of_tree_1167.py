from sys import stdin
from math import inf

n = int(stdin.readline())

# 이동 최소비용을 저장할 2차원 배열
cost = [[inf] * n for _ in range(n)]
for row in range(n):
	row_list = list(map(int, stdin.readline().split()))	
	#print(f"{row_list=}")
	for idx in range(1,len(row_list)-1, 2):
		#print(f"{idx=}")
		col = row_list[idx]-1
		val = row_list[idx+1]
		cost[row][col] = val

# 플로이드 와샬 알고리즘 적용
for k in range(n):
	cost[k][k] = 0
	for i in range(n):
		for j in range(n):
			cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

diameter = max(cost[0])
for row in range(1, n):
	if diameter < max(cost[row]):
		diameter = max(cost[row])

print(diameter)