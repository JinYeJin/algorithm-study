n,k = map(int, input().split())

coin = []
for _ in range(n):
	tmp = int(input())
	if  tmp <= k:
		coin.append(tmp)

i = len(coin)-1
cnt = 0
while k >0:
	quotient = k //coin[i]
	cnt += quotient
	k -= quotient * coin[i]
	i -= 1
		
print(cnt)

'''
지불할 수 없는 경우가 주어지지 않았기 때문에 통과되었다.
지불할 수 없는 경우가 있다면 따로 처리해야함
'''