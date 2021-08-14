# decrease num 1038
#expo = 2
# 자릿수가 11인 경우 -1 return 해야함

def next_num(num, expo):
	print(f"{num=} in next_num method")
	print(f"{expo=} in next_num method")
	expo -= 1	
	num += (10** expo)
	# num = 332
	while expo:
		diff = num % (10** expo)
		num -= diff
		expo -= 1

	print(f"after {num=} in next_num method")
	print(f"after {expo=} in next_num method")
	return num

n = int(input())
cnt = 0
num = 0
times = 20
while (n >= cnt and times):	#n이 0이 될때까지
	expo = 1
	prev = -1
	print(f"{num=}")
	# 10 // 10
	# 10 // 100
	# while문이 자릿수만큼 반복되어야한다.
	#10 2, 100 3
	while (num // (10**expo)): # 1의 자릿수부터 큰 자릿수까지
		# 10
		# 123
		digit = num % (10**expo)
		digit = digit // (10**(expo-1))
		# digit = 0, prev = -1
		print(f"{prev=}")
		print(f"{digit=}")
		print(f"{expo=}")
		
		if prev >= digit:
			num = next_num(num, expo)
			break
		else:
			expo += 1
			prev = digit
	else: # 반복문이 끝까지 돌고 나온 경우에만 적용된다.
		num = next_num(num, expo)
		cnt += 1
	print(f"{cnt=}\n")
	times -= 1
	
print(num)
