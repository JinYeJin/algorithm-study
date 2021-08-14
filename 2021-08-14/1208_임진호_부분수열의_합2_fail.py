from itertools import combinations

N, S = map(int, input().split())
num_list = [ int(x) for x in input().split() ]
num_list.sort()
cnt = 0
for i in range(1, len(num_list)+1):	
	for subset in list(combinations(num_list, i)):
		sum_subsquece = sum(subset)
		if sum_subsquece == S:
			cnt += 1
			
print(cnt)
'''
2%에서 시간초과
가능할만한 집합만 부분집합으로 구성한다.
어떻게?
1. 정렬한다.
2. 일부만 더한 뒤 target숫자와 차이를 가지고 
   target숫자를 만들수 있는 숫자들만 더한다
이런다고 연산량을 충분히 줄일 수 있는가?
'''
