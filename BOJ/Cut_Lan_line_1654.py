from sys import stdin

k,n = map(int, input().split())
given_lan = [int(stdin.readline()) for _ in range(k) ]
start = 1
end = max(given_lan)

while start<= end:
	mid = (start+end)//2
	cnt = 0
	
	for i in given_lan:
		cnt += i//mid
	
	if 	cnt >= n:
		start = mid +1
	else:
		end = mid -1

print(end)