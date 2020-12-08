def solution(n, computers):
	network_count=0
	#visited=[False for _ in range(n)]
	adjacency_list = {}
	
	for i in range(n):
		adjacency_list[i] = []
		for j in range(len(computers[i])):
			if computers[i][j]==1 and i!=j:
				adjacency_list[i].append(j)

	visited = []
	for node in adjacency_list:
		if node in visited:
			continue

		to_visit = [node]

		while to_visit:
			u = to_visit.pop()
			visited.append(u)
			for v in adjacency_list[u]:
				if v not in visited+to_visit:
					to_visit.append(v)
					
		network_count += 1
				
	return network_count

n=3
computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
print(solution(n, computers))