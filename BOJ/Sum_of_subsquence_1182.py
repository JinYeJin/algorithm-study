#Sum_of_subsquence_1182
from itertools import combinations

N, S = map(int, input().split())
num_list = [ int(x) for x in input().split() ]
cnt = 0
for i in range(1, len(num_list)+1):
	answer = list(combinations(num_list, i))
	
	for idx in range(len(answer)):
		sum_subsquece = sum(answer[idx])
		if sum_subsquece == S:
			cnt += 1
			
print(cnt)