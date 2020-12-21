#1744 number_binding
def find_pos_boundary(num, num_len):
	start = 0
	if num_len==2 and num[-1] > 0:
		end = num_len
	else:
		end = num_len-1

	while start <= end:
		mid = (start+end)//2		
		if num[mid] > 0 and num[mid-1] <= 0:
			return mid
		elif num[mid-1] > 0:
			end = mid-1
		elif num[mid] <= 0:
			start = mid+1
	
	return -1

import sys

num_len = int(sys.stdin.readline())
num = []
for _ in range(num_len):
	num.append(int(sys.stdin.readline()))
count_1 = num.count(1)

num.sort()
pos_boundary_idx = find_pos_boundary(num, num_len)
sum = 0
neg_bool = True
pos_bool = True

#0 또는 음수 / 양수만 들어온 경우
if pos_boundary_idx == -1:
	if num[-1] > 0:
		neg_bool = False
		pos_boundary_idx = 0
	else:
		pos_bool = False
		pos_boundary_idx = num_len

#양수 개수가 짝수인지 홀수인지 확인
if pos_bool:
		if (num_len - pos_boundary_idx) % 2 == 0:
			pos_last = pos_boundary_idx-1	
		else:#홀수인경우 sum에 가장 작은 값을 미리 더 해준다.
			pos_last = pos_boundary_idx
			sum += num[pos_boundary_idx]				
				
		for idx in range(num_len-1, pos_last,-2):
			if num[idx] == 1 or num[idx-1] == 1:
				sum += num[idx] + num[idx-1]
			else:
				sum += num[idx]*num[idx-1]

if neg_bool:
		if pos_boundary_idx % 2 == 0:    
			neg_last = pos_boundary_idx
		else:
			neg_last = pos_boundary_idx-1
			sum += num[pos_boundary_idx-1]
			
		for idx in range(0,neg_last, 2):
			sum += num[idx]*num[idx+1]

print(sum)