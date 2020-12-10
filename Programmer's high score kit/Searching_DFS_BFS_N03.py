def solution(begin, target, words):
	
	#단어 리스트에 없으면 return 0
	if not target in words:
			return 0
	
	#bfs순회를 위해서 시작 단어가 단어 리스트에 없으면 추가한다.
	if not begin in words:
			words.append(begin)
			
	words_count = len(words)
	word_len = len(begin)
	
	adj_list = {}
	#인접리스트로 구성
	for i in range(words_count):
			adj_list[i] = []
			for j in range(words_count):
					#현재 단어가 인접리스트에 들어갈 필요가 없으므로 일치하지 않을때만 추가
					if i != j:                
							cnt = 0
							for k in range(word_len):
									if words[i][k] == words[j][k]:
											cnt += 1
											
							#철자 1개만 달라야 변환 가능하므로 -1
							if cnt == word_len-1:
									adj_list[i].append(j)
	
	begin_index = words.index(begin)
	tager_index = words.index(target)
	bfs_queue = [begin_index]
	distance = [ -1 for _ in range(words_count) ]
	distance[begin_index] = 0

	#bfs순회 및 시작정점으로부터의 거리 기록
	while bfs_queue:
			u = bfs_queue.pop(0)			
			for i in adj_list[u]:
					if distance[i] ==  -1:
							distance[i] = distance[u] +1
							bfs_queue += adj_list[u]
	
	return distance[tager_index]


begin='hit'
target='cog'
words = ['hot', 'dog', 'cog', 'lot', 'dot']
print(solution(begin, target, words))

'''
def solution(begin, target, words):
	step = 0
	
	if not target in words:
		return step
		
	#인접리스트 구성을 위해 words에 없으면 begin을 포함시킴
	if not begin in words:
		words.append(begin)
	
	word_count = len(words)
	word_len = len(words[0])
	adj_list = {}
	
	#인접리스트 구성
	for i in range(word_count-1,-1,-1):
		cnt=0
		adj_list[words[i]] = []
		for j in range(word_count-1,-1,-1):
			if i!=j:
				for k in range(word_len):
					if words[i][k] == words[j][k]:
						cnt += 1
				
				if cnt == word_len-1:
					adj_list[words[i]].append(words[j])
		
	i=0
	words_queue = []
    adj_list[begin]
    distance = [ -1 for _ in range(word_count)]
	words_queue.append(adj_list[begin])
	
	while words_queue:
		u = words_queue.pop(0)
        
	
	return step
'''