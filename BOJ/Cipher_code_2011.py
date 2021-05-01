num_str = input()
num_list = [ int(num) for num in list(num_str)]
num_digits = len(num_list)
dp = [0] * (num_digits+1)
dp[0] = 1
for i in range(1, num_digits+1):
	if 1<= num_list[i-1] <= 9:
		dp[i] += dp[i-1]
		
	if i == 1:
		continue
	tmp = num_list[i-2] * 10 + num_list[i-1]
	if 10 <= tmp <= 26:
		dp[i] += dp[i-2]
		
print(dp[num_digits] % 1000000)