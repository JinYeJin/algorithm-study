# sum_of_square

memo = {0:0, 1:1}

def routine(n):
	if n in memo:
		return memo[n]
	
	near_square_root = int(n ** 0.5)
	near_square = near_square_root ** 2
	remainder = n - near_square
	
	if remainder ==0:
		memo[n] = 1
		return 1
	
	min_cnt = routine(near_square) + routine(remainder)
	start =  near_square_root -1
	end = int((n//2)**0.5) -1

	for square_root in range(start, end, -1):
		remainder = n - square_root**2
		cnt = routine(square_root**2) + routine(remainder)
		if cnt < min_cnt:
			min_cnt = cnt
	
	memo[n] = min_cnt
    
	return min_cnt

n = int(input())
print(routine(n))