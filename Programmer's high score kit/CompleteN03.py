def solution(brown, yellow):
	sum = brown/2 +2	#가로세로 합
	area = brown+yellow
	start =  brown//4+1# 가로길이 시작 숫자
	end = brown//2+1
	

	while start<=end:
		mid = (start+end)//2
		if mid*(sum-mid) == area:
			return [mid,int(sum-mid)]
		elif mid*(sum-mid) > area:
			start = mid+1
		else: #mid*(sum-mid) < area
			end = mid-1

brown = 24
yellow = 24 
print(solution(brown, yellow))


