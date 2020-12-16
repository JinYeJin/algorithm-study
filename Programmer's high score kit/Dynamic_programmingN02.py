def solution(triangle):
	t_h = len(triangle)
	t_w = [ [0 for _ in range(layer+1)] for layer in range(t_h) ]
		
	t_w[0][0] = triangle[0][0]
	for layer in range(1, t_h):        
		for room in range(layer):
			if room == 0:
					t_w[layer][room] = triangle[layer][room] + t_w[layer-1][room]
			elif room == layer:
					t_w[layer][room] = triangle[layer][room] + t_w[layer-1][room-1]
			else: 
					t_w[layer][room] = triangle[layer][room] + max(t_w[layer-1][room-1], t_w[layer-1][room])
			
	return max(t_w[t_h-1])


triangle = [['7'], ['3', '8'], ['8', '1', '0'], ['2', '7', '4', '4'], ['4', '5', '2', '6', '5']]	
print(solution(triangle))
#30

'''
다른이의 코드
효율성 나의 2배
zip을 쓰는 부분, 람다처리 등이 주효해보임
solution = lambda t, l = []: max(l) if not t else solution(t[1:], [max(x,y)+z for x,y,z in zip([0]+l, l+[0], t[0])])


'''