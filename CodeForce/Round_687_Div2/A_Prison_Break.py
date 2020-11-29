n = int(input())
result = []
for _ in range(n):
	m,n,r,c = map(int, input().split())
	coners = [ [1,1], [1,n], [m,1], [m,n] ]
	t = 0
	for corner in coners:
		if t <abs(r-corner[0]) + abs(c-corner[1]):
			t = abs(r-corner[0]) + abs(c-corner[1])
	result.append(t)

for ele in result:
	print(ele)
