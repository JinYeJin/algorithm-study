from itertools import permutations 

def solution(numbers):
	answer = 0
	all_cases = []
	prime = []
	numbers = list(numbers)
	
	for number in range(1,len(numbers)+1):
		splice = ""
		for n in permutations(numbers, number):
			splice += n
			if int(splice) not in all_cases:
				all_cases.append(int(splice))
	
	for number in all_cases:
		for x in range(2, number+1):
			number%


'''


'''

numbers = "171"
solution(numbers)
	
	
	
	return answer
	
	
'''
from itertools import permutations
a = [1,2,3]
permute = permutations(a,2)
print(list(permute))
'''
결과
'''
[(1,2),(1,3),(2,1),(2,3),(3,1),(3,2)]

'''