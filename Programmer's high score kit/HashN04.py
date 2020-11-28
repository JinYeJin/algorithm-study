def solution(generes, plays):
	answer = []
	generes_dict = {}
	generes_sum_dict = {}
	# 장르별 해시, 장르별 재생수 해시에 값 추가
	for index, genere in enumerate(generes):        
		if not generes_dict.get(genere):
			generes_sum_dict[genere] = plays[index]
			generes_dict[genere] = {'songs': {index: plays[index]} }
		else:			
			generes_sum_dict[genere] += plays[index]	
			generes_dict[genere]['songs'][index] = plays[index]
		
	#장르별 재생수, 고유번호 순으로 내림차순 정렬
	for genere in generes_dict:
		play_sorted = sorted(generes_dict[genere]['songs'].items(), key=lambda x: (-x[1], x[0]))
		generes_dict[genere]['songs'] = play_sorted

	#재생수가 많은 장르 순서대로 반복
	for genere in sorted(generes_sum_dict.items(), key=lambda x: x[1], reverse=True):
		if len(generes_dict[genere[0]]['songs']) >1:
			for i in range(2):
				answer.append(generes_dict[genere[0]]['songs'][i][0])
		else:
			answer.append(generes_dict[genere[0]]['songs'][0][0])
	return answer


'''
다른 사람의 코드

# 큰 틀만 해시이고 나머지는 배열로 구현
def solution(genres, plays):
    genres_dict = {}
    genres_list = []
    for i in range(len(genres)):
        if genres[i] not in genres_dict:
            genres_dict[genres[i]] = []
        genres_dict[genres[i]].append([i, plays[i]])

    for g in genres_dict:
        genres_dict[g].sort(key=lambda x: x[1], reverse=True)
        genres_list.append([g, sum([play for _, play in genres_dict[g]])])

    genres_list.sort(key=lambda x: x[1], reverse=True)
    answer = []
    for g, _ in genres_list:
        answer.extend([x[0] for x in genres_dict[g][:2]])
    return answer

'''
