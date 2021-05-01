from collections import deque

start, target = map(int, input().split())
start_len = len(start)
target_len = len(target)

result = -1
queue = deque([(start, 1)])

while queue:
	i, cnt = queue.popleft()
	if i == end:
		result = cnt
		break
	
	if i * 2 <= end:
		queue.append((i*2, cnt+1))
	
	if int(str(i)+'1') <= end:
		queue.append(int(str(i)+'1'), cnt+1))
		
print(res)



# way2
start, target = map(int, input().split())
result = 1
queue = deque([(start, 1)])

while True
	
	if target == start:
		break
	
	elif (target % 2 != 0 and target % 10 != 1) or (target < start):
		cnt = -1
		break
	else:
		if target % 10 == 1:
			target //= 10
			cnt += 1
		else:
			target //= 2
			cnt += 1

print(cnt)


target에서 start로 줄여나아간다.
whule 문을 통해 반복
a == b면 while문을 break
b가 2로 나누어 떨어지지 않으며 b의 마지막 자리의 숫자가 1이 아니거나 
b가 a보다 작다면 b에서 a를 만들 수 없는 경우 (a에서 b를 만들 수 없는 경우이므로 -1을 출력한다.)

만약 b의 마지막 숫자가 1이면 b에서 1을 제거한다.
만약 b가 2로 나누어 떨어지면 2로 나눈다.



# way3
current, target = map(int, input().split())
cnt = 1

while True:
	if current == target:
		break
	elif current > target:
		cnt = -1
		break
	elif target % 2 == 0:
		target //= 2
		cnt += 1
	elif target % 10 == 1:
		target //= 10
		cnt += 1
	else:
		cnt = -1
		break
		
print(cnt)
	
		
## way4 (method)

def a_to_b(num1, num2):
	cnt = 1
	
	while TrueL
		if num1 > num2:
			return -1
		
		if num1 == num2:
			return cnt
			
		if num2 % 10 == 1:
			num2 = (num2 - 1) // 10
			cnt += 1
		
		else:
			num2 /= 2
			cnt += 1
			if num2 != int(num2)
				return -1

a, b = map(int, stdin.readline().split())

print(a_to_b(a, b))

## way5
a,b=map(int,input().split());r=1
while a<b:b=(~b%2*5|-b%5//4)*b//10;r+=1
print(-(a>b)|r)






