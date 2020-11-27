def solution(numbers)
    answer = 0
	lcase = []
	lprime = []
    lNumbersArr = numbers.chars	
	lNumberslength = lNumbersArr.length
		
	#nP1, nP2, ... , nPn-1, nPn의 총합 가짓수
	i=1
	while i <= lNumberslength
		lPermuArray = lNumbersArr.permutation(i).to_a
		j=0		
		lPermuArray.each do |combineArr|
			lcombine = combineArr.join.to_i
			
			next if lcombine <= 1 || lcase.include?(lcombine)
			
			lcase << lcombine
			initial = 1
			cnt=0
			while initial < lcombine
				initial += 1
			
				if lcombine%initial == 0
					cnt +=1
				end
			
				if  cnt >=1 && initial< lcombine				
					break
				end
				#루비에서는 그 안에서 그때 그때 확인했던거 같네요 소수인지
			end
			
			if cnt == 1 && lcombine == initial
				lprime << lcombine
			end	
			
		end
		i += 1
	end
	# 마지막에 소수 배열 길이 반환
	# 질문 있으신가요
	# 다음에는 구매할려고요 ㅜ  소프트웨어 문제일 수도 있어서 디스코드 그걸로 확인해볼게요
	
	answer = lprime.lenth	
    return answer
end




numbers = "1152"
solution(numbers)