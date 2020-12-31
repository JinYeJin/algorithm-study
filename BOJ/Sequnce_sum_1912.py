N = int(input())
num_list = [ int(x) for x in input().split() ]
max_val = num_list[0]
tmp_max = num_list[0]

for idx in range(1,N):
	if tmp_max < 0 and num_list[idx] > 0:
		tmp_max = num_list[idx]
	else:
		tmp_max += num_list[idx]
		
	max_val = max(max_val, tmp_max, num_list[idx])
	
print(max_val)

'''
n = int(input())
num_list = list(map(int, input().split()))
temp = [0 for _ in range(n)]
result = -1001

for i in range(n):
    temp[i] = max(temp[i-1] + num_list[i], num_list[i])
    result = max(result, temp[i])
        
print(result)
'''