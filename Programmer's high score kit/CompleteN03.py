def solution(brown, yellow):
	sum = brown/2 +2	#가로세로 합
	area = brown+yellow
	start =  brown//4+1# 가로길이 시작 숫자
	end = brown//2+1
	
	while start<=end:
    # 가로 세로가 가로가 세로보다 같거나 크다해서
    #그걸 이용했습니다 
    
		mid = (start+end)//2 # 가로길이
		if mid*(sum-mid) == area:
			return [mid,int(sum-mid)]
		elif mid*(sum-mid) > area:
			start = mid+1
		else: #mid*(sum-mid) < area
			end = mid-1
            


