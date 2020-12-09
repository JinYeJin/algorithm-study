def solution(people, limit):
	answer = 0	
	people.sort()
	
	i=len(people)-1
	j=0
	while i >= 0 and i>=j:
		looking = limit - people[i]
		i -= 1
		if people[j]<=looking:
			j +=1
			answer += 1
		else:
			answer += 1
			
	return answer