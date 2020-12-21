#make one

memo={1:0, 2:1}
def routine(n):
	if n in memo:
		return memo[n]
	m = 1 + min(routine(n//2)+n%2, routine(n//3)+n%3)
	memo[n] = m
	
	return m

n = int(input())
print(routine(n))


'''
#bottom up
num = int(input())

result = [0 for _ in range(num + 1)]

for i in range(2, num + 1):
	result[i] = result[i-1] + 1
	if i % 3 == 0 and result[i//3] + 1 < result[i]:
		result[i] = result[i//3] + 1
	if i % 2 == 0 and result[i//2] + 1< result[i]:
		result[i] = result[i//2] + 1
	#print(f"{result=}")
	#print(f'result[{i}]: {result[i]}')

print(result[num])
'''
