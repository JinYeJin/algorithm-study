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
				
			end
			
			if cnt == 1 && lcombine == initial
				lprime << lcombine
			end	
			
		end
		i += 1
	end
	
	answer = lprime.lenth	
    return answer
end




numbers = "1152"
solution(numbers)