def solution(n,a,b):
    answer = 0
    while (a!=b):
        if a % 2 != 0: 
            a += 1
        if b % 2 != 0:
            b += 1
        a /= 2
        b /= 2
        answer += 1
    return answer

n, a, b = 8, 4, 7
print(solution(n,a,b))


'''

def log_binary_search(target, two_powers):
	begin = 0
	end = len(two_powers)-1	
	print(f"{target=}")
	while (begin <= end):
		print(f"{begin=}")
		print(f"{end=}")
		mid = (begin+end)//2
		if two_powers[mid] == target:
			return mid
		elif two_powers[mid] < target:
			begin = mid+1
		else:
			end = mid-1
	return mid+1

def solution(n,a,b):
	if n == 0:
		return 1
	two_powers =[ 2 ** power for power in range(1, n+1) ]
	print("two_powers : ", two_powers)
	print("a : ", a)
	print("b : ", b)

	first_log = log_binary_search(a, two_powers)
	second_log = log_binary_search(b, two_powers)
	print(f"{first_log=}")
	print(f"{second_log=}")	
	if first_log != second_log:
		return max(first_log, second_log)
	else:
		# diff = abs(a-b)
		# diff_log = int(math.log(diff, 2)) 
		# if diff not in two_powers:
		# 	diff_log += 1
		# return diff_log
		a -=  2 ** (first_log-1)
		b -=  2 ** (first_log-1)
		return solution(first_log-1,a,b)
		# 6 7 (2 3)
		#  257 380
		#  1   124
		#  1   7

		# 510 511 (254 255 ) 126 127 (62 63) 30 31 (14 15) 6 7 (2 3)
		# 512 - 256
		# 2 ** 8
		# 258 259


'''

'''
1. log_2_x 했을때 어떤 범위에 들어가는지 확인
	-1 binary search로 탐색
	512, 513
	최대 범위 2 ** N
2. 둘(x,y)이 같은 범위(range)에 있으면 
   -1 둘의 차이가 2의 제곱이 아니라면.
   return log_2_|x - y| + 1
   -2 2의 제곱이라면
	return log_2_|x - y|
	
3. 둘(x,y)이 다른 범위(range)에 있으면
   return max(x_range, y_range)
   15 (4), 27 (5)

log를 쓰는거 자체가 속도를 많이 느리게 만든다.
다른 방법으로 log_2를 취했을때의 범위를 알아야한다.
방법은
twO_powers 리스트에서 어떤 범위에 속하는지 알아내는것이다.


two_powers :  [2, 4, 8, 16, 32, 64, 128, 256, 512]
first_log, second_log :  9 9
a, b :  255 254
two_powers :  [2, 4, 8, 16, 32, 64, 128, 256]
first_log, second_log :  8 8
a, b :  127 126
two_powers :  [2, 4, 8, 16, 32, 64, 128]
first_log, second_log :  7 7
a, b :  63 62
two_powers :  [2, 4, 8, 16, 32, 64]
first_log, second_log :  6 6
a, b :  31 30
two_powers :  [2, 4, 8, 16, 32]
first_log, second_log :  5 5
a, b :  15 14
two_powers :  [2, 4, 8, 16]
first_log, second_log :  4 4
a, b :  7 6
two_powers :  [2, 4, 8]
first_log, second_log :  3 3
a, b :  3 2
two_powers :  [2, 4]
first_log, second_log :  2 1
2

---
log로 풀 필요도 없다.
시간초과가 발생한다.

짝수로 만들고 둘이 다른동안 나누기만한다
나눌때마다 카운팅하면
최종적으로 몇번의 단계가 지나야하는지 알 수 있다.
'''