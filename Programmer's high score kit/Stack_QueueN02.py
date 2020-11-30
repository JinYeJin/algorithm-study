from collections import deque
def solution(progresses, speeds):
	answer = []
	p_q = deque(progresses)
	s_q = deque(speeds)
	
	while p_q:
		for i in range(len(p_q)):
			if p_q[i] < 100:
				p_q[i] += s_q[i]
				
		i = 0
		while i < len(p_q) and p_q[i] >= 100:
			i +=1
			
		if i > 0:
			answer.append(i)
			for _ in range(i):
				p_q.popleft()
				s_q.popleft()
	
	return answer



'''
# 다른 이의 코드

# 음수를 이용한 올림
def solution(progresses, speeds):
    Q=[]
    for p, s in zip(progresses, speeds):
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    return [q[1] for q in Q]
    
    
# 배열 큐, 읽기 쉬운 구조의 코드
def solution(progresses, speeds):
    print(progresses)
    print(speeds)
    answer = []
    time = 0
    count = 0
    while len(progresses)> 0:
        if (progresses[0] + time*speeds[0]) >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            time += 1
    answer.append(count)
    return answer



---
# deque 삭제 배열로 구성 
성능차이 미미함
def solution(progresses, speeds):
    answer = []

    while progresses:
        for i in range(len(progresses)):
            if progresses[i] < 100:
                progresses[i] += speeds[i]

        i = 0
        while i < len(progresses) and progresses[i] >= 100:
            i +=1

        if i > 0:
            answer.append(i)
            for _ in range(i):
                progresses.pop(0)
                speeds.pop(0)

    return answer


'''