from sys import stdin

n, c = map(int, input().split())
house = [ int(stdin.readline()) for _ in range(n) ]
start = 1#house[1] - house[0]
end = house[1] - house[0]

while start <= end:
	mid = (start + end)//2
	#첫번째 집에는 공유기를 놓는다는 가정
	home = house[0]
	router = 1
	
	for i in range(1, n):
		if home + mid <= house[i]:
			router += 1
			#최근에 공유기가 설치된 집으로 변경
			home = house[i]
	
	#집끼리 거리가 멀어서 router가 적게 설치된 경우
	if router < c:
		end = mid -1
	
	#거리가 알맞거나 router가 더 많이 설치된 경우
	else:
		start = mid +1
		fit = mid

print(fit)

