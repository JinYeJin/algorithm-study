def solution(number, k):
	num_len = len(number)
	be_remained_len = len(number) -k
	num_stack = [number[0]]
	i = 1	
	while i < num_len:
			stack_size = len(num_stack)
			remained_count = num_len - i
			
			#남은 number문자열 순회 횟수 + stack 크기 > number에서 k개를 제거하고 남아 있어야할 숫자열 길이, 단 스텍 길이는 남아있어야할 문자열 길이를 못 넘음
			if remained_count + stack_size > be_remained_len and stack_size <= be_remained_len:					
					if be_remained_len <= remained_count:
							max_loop_times = stack_size
					else:
							max_loop_times = remained_count + stack_size - be_remained_len
					
					last_num = None
					for _ in range(max_loop_times):
							if num_stack[-1] >= number[i] and stack_size < be_remained_len:
									num_stack.append(number[i])
									last_num = None
									break
							elif num_stack[-1] < number[i]:
									num_stack.pop()
									last_num = True
									
					if last_num:
							num_stack.append(number[i])
							
			else:
					if stack_size > be_remained_len:
						num_stack= num_stack[:be_remained_len]
					else:
						until = be_remained_len - stack_size
						num_stack += number[i:i+until+1]
					break
			
			i += 1
	
	return ''.join(num_stack)

k = 2
number = "777"
print(solution(number, k))

'''
# 다른이의 코드 
def solution(number, k):
	st = []
	for i in range(len(number)):
		while st and k > 0 and st[-1] < number[i]:
			k -= 1
			st.pop()
		st.append(number[i])
	return ''.join(st[:len(st)-k])
'''