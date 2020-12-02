def solution(priorities, location)
    answer = 0
	
	ldocuments = []
	ldocumentResult = []

	priorities.each_with_index do |item, index|
		lTmpHash={}
		lTmpHash[:priority] = item
		lTmpHash[:default_index] = index
		ldocuments << lTmpHash
	end

	while ldocuments.length > 0	
		
		if ldocuments.length  == 1
			answer +=1			
			return answer
		end
		
		i = 1
		lbiggestPriority = ldocuments[i][:priority]
		
		while i < ldocuments.length-1 # 대기열 증 기장 큰 우선순위 값
		
			if ldocuments[i+1][:priority] > lbiggestPriority
				lbiggestPriority = ldocuments[i+1][:priority]			
			end			
			i +=1
			
		end

		if ldocuments[0][:priority] >= lbiggestPriority # 대기열에 있는 문서들의 우선순위보다 높은경우
			
			answer +=1
			if location == ldocuments[0][:default_index]
			
				return answer
				# 에러가 발생할 경우는 없는가? 애초에 위치가 없다든가
			end
			ldocuments.delete_at(0)
			ldocumentResult << ldocuments[0]
		
		else
			ldocuments.push(ldocuments[0])
			ldocuments.delete_at(0)			
		
		end
		
	end
    
end


## 파이썬 답 참조 
def solution(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)] 
	# enumerate는 해당 배열의 요소값 별로 인덱스 값도 반환해준다 ex) (index, value)
    answer = 0
    while True:
        cur = queue.pop(0) # 메소드를 넣는 방식 어떤 값인가? Cur에 첫번째 값만 들어가나 아니면 첫번째만 빼고 나머지 큐가 들어가나
        if any(cur[1] < q[1] for q in queue):
		# cur와 q는 무엇인가 
            queue.append(cur)
			# cur는 무엇인가 첫번째 인덱스만 의미하나?
        else:
            answer += 1
            if cur[0] == location:
                return answer




