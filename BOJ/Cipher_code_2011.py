num_str = input()
num_list = [ int(num) for num in list(num_str) ]
nc = [0] * (len(num_list)+1) #+1?
nc[0] = 1
for i in range(1, len(num_list)+1):
	if 1 <= num_list[i-1] <= 9:
		nc[i] += nc[i-1]
			
	if i == 1:
		continue
	temp = num_list[i-2] * 10 + num_list[i-1] 
	if 10 <= temp <= 26:
		nc[i] += nc[i-2]
		
print(nc[len(num_list)] % 1000000)