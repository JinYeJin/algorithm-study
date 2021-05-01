import sys

input = sys.stdin.readline

n, m = map(int, input().split())
days = []

for _ in range(n):
	days.append(int(input()))

begin = max(days)
end = sum(days)

cnt = 0
change = 0
# 100 + 500

# k == 300 시작값
# m == 5
# k == 100가 될떄 최소 인출액
#1 2 3 4 5 6 7
#100 100 100 50 50 5O 5O 
while begin <= end:
	k = (begin + end)//2
	cnt = 1
	change  += k

	for idx, day in enumerate(days):
		if change < day:
			cnt += 1
			change = k
		change -= day

	change = 0
	#if m == cnt
		#break
	if m < cnt:# 인출횟수가 더 많은 경우 
		begin = k + 1
	elif m >= cnt:
		end = k - 1

print(k)