def solution(target, broken):
	enable = {str(i) for i in range(10)}  # 0, 1, 2 ... 9 (가능한 수)
	the_ch = {100:0, 99:1, 98:2}

	if target in the_ch:
		return the_ch[target]

	if broken != 0:
		enable -= set(map(str, input().split()))  # 고장난 버튼 리스트 제거

	# case1 (100번에서 +, - 로만 움직이는 경우)
	min_cnt = abs(100 - target)

	# case2 (1,000,000 채널까지 브루트 포스 진행)
	# 500,000 채널까지 존재하기 때문에 500,000 보다 크면서 모든 숫자의 경우를 거치는 1,000,000까지를 범위로 잡음
	for num in range(1000001):
		num = str(num)
		for j in range(len(num)):
			if num[j] not in enable:
				break
			elif j == len(num) - 1:
				min_cnt = min(min_cnt, abs(target - int(num)) + len(str(num)))
	
	return min_cnt

target = int(input())
broken = int(input())
print(solution(target, broken))
