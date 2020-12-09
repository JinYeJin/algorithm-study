import heapq
def solution(scoville, K):
	answer = 0
	heapq.heapify(scoville)

	while len(scoville) > 1 and scoville[0] < K:
		mixed = heapq.heappop(scoville)+heapq.heappop(scoville)*2
		heapq.heappush(scoville, mixed)
		answer += 1
	# 왜 길이가 1인지 그리고 최솟값이 k보다 작은지 검사하는 걸 반복문 밑에서 검사해야지만 되는가?
	# 음식 갯수가 2보다 작은데 K값은 높아서 도달하지 못하는 경우로 보인다.
	if len(scoville) <= 1 and scoville[0] < K:
		return -1

	return answer


'''
다른이의 코드 혹은 방법
- 배준혁님
queue만 써서 풀었는데도 시간이 heap을 쓴 풀이의 절반 정도 걸리네요. 
저는 섞어서 나온 새로운 값, mix들을 별도의 queue에 넣었는데 이게 가장 큰 요인같네요. 
나중에 나온 mix값이 먼저 나온 것보다 클 수밖에 없어서 
섞는 순서대로 queue에 넣어주면 크기 순서를 신경 쓸 필요가 없어요. 
그냥 popleft로 꺼내면 무조건 mix값의 최소입니다ㅎ


'''