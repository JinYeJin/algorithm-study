import itertools 

def solution(numbers, target):
	count = 0
	lsum = sum(numbers)

	if lsum == target:
		return 1
	elif lsum < target:
		return count
	if (lsum-target)%2 !=0:
		return count
	else:
		lKeyNumber = (lsum-target)/2
		
	lsmalls = []
	
	for item in numbers:
		if lKeyNumber == item:
			count +=1
		elif lKeyNumber > item:
			lsmalls.append(item)
	
	for i in range(2, len(lsmalls) ):
		for item in list(itertools.combinations(lsmalls, i)):
			if lKeyNumber == sum(item):
				count +=1
	
	return count