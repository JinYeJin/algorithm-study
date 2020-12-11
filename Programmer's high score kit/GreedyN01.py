def solution(n, lost, reserve):
	answer = 0    
	recover = []
	for student in lost:
		if student in reserve:
			recover.append(student)
			reserve.remove(student)

	for student in recover:
		if student in lost:
			lost.remove(student)

	recover = []
	
	for student in lost:		
		if student-1 in reserve:
			recover.append(student-1)			
			reserve.remove(student-1)            
		elif student+1 in reserve:
			recover.append(student+1)
			reserve.remove(student+1)

	for student in recover:
		if student-1 in lost:
			lost.remove(student-1)
		elif student+1 in lost:
			lost.remove(student+1)

	answer = n-len(lost)
	return answer