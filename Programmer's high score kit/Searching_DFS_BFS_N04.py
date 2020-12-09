def solution(tickets):
	path = []
	ticket_count = len(tickets)
	used = [0 for _ in range(ticket_count)]
	cnt=0	
	start="ICN"
	path.append(start)
	while cnt < ticket_count:
		
		compare = [] 
		for i in range(ticket_count):	
			if used[i]==0 and  start == tickets[i][0]:
				if compare ==[] or compare[1] > tickets[i][1]:
					# 알파벳 앞서는 걸로도 경로가 있는지 확인
					# ex) tickets =[['ICN', 'A'], ['ICN', 'B'], ['B', 'ICN']]
					for j in range(ticket_count):	
						if used[j]==0 and  tickets[i][1] == tickets[j][0]:
							compare = [i,tickets[i][1]]
                        #마지막 티켓인 경우 확인
						elif used[j]==0 and len(path) ==  ticket_count:
							compare = [i,tickets[i][1]]
		
		path.append(compare[1])
		start = compare[1]
		used[compare[0]] =1
		cnt += 1

	return path

tickets = [['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['ATL', 'ICN'], ['ATL','SFO']]
#tickets = [['ICN', 'JFK'], ['HND', 'IAD'], ['JFK', 'HND']] 
#tickets =[['ICN', 'A'], ['ICN', 'B'], ['B', 'ICN']]
print(solution(tickets)) 