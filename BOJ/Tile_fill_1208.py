from sys import stdin, stdout

N = int(stdin.readline()) 

#bottom up
cases = [0] * 31 
#base case
cases[2] = 3

#짝수만 가능, 2일때는 알고 있으므로 다음 짝수 4부터 시작하며, 2씩 간격을 둠
for i in range(4, N+1, 2): 
	cases[i] = 2 + cases[i-2] * 3 + sum(cases[:i-2]) * 2 

#bottom up 이므로 마지막 위치에 최적해가 담김	
stdout.write(str(cases[N]))

