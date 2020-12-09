# 얼음이 어디까지 이어져있는지 확인하는 DFS
def check_iceberg_blocks(area, visited, x, y):
	import sys
	sys.setrecursionlimit(100000)
    
	visited[x][y] = 1	
	if x-1 >= 0 and visited[x-1][y] == 0 and area[x-1][y] != 0:
		check_iceberg_blocks(area, visited, x-1, y)
		
	if y+1 < len(visited[0]) and visited[x][y+1] == 0 and area[x][y+1] != 0:
		check_iceberg_blocks(area, visited, x, y+1)
		
	if x+1 < len(visited) and visited[x+1][y] == 0 and area[x+1][y] != 0:
		check_iceberg_blocks(area, visited, x+1, y)
		
	if y-1 >= 0 and visited[x][y-1] == 0 and area[x][y-1] != 0:
		check_iceberg_blocks(area, visited, x, y-1)

#얼음덩어리 개수 파악하는 함수
def count_iceberg_blocks(area, iceberg, visited):
	block_count = 0
	for ice in iceberg:
		x,y = ice[0], ice[1]
		if visited[x][y] != 0:
			continue
		else:
			check_iceberg_blocks(area,visited, x, y)

		block_count += 1
				
	return block_count


def main():
	import copy
	year = 0
	area = []
	iceberg = []
	row,col = map(int, input().split())

	for _ in range(row):
		area.append(list(map(int, input().split()) ) )

	#얼음만 있는 배열생성  [x좌표, y좌표, 빙산높이]
	for x in range(row):
		for y in range(col):
			if area[x][y] != 0:
				iceberg.append([x, y, area[x][y]])
				
	# visited 배열 없이 할 수 있는 방법은?
	visited = [[0 for _ in range(col)] for _ in range(row)]
	# 2 덩어리 이상인 경우
	if count_iceberg_blocks(area, iceberg, visited) > 1:	
		return year
	
	#빙산이 녹기 전까지 반복
	while iceberg:
		#얼음 녹는 과정
		#print(f"Before melting {iceberg=}")
		for i, ice in enumerate(iceberg):	
			x,y = ice[0], ice[1]
			if x-1 >= 0 and area[x-1][y] == 0 and iceberg[i][2]>0:
				iceberg[i][2] -= 1
		
			if y+1 < col and area[x][y+1] == 0 and iceberg[i][2]>0:
				iceberg[i][2] -= 1
		
			if x+1 < row and area[x+1][y] == 0 and iceberg[i][2]>0:
				iceberg[i][2] -= 1
			
			if y-1 >= 0 and area[x][y-1] == 0 and iceberg[i][2]>0:
				iceberg[i][2] -= 1
		
		#전체가 다 녹기까지 옆에 것이 녹아서 바다가 된것에 영향 받으면 안되어서 area리스트는 얼음이 녹고나서 적용한다.
		for i, ice in enumerate(iceberg):	
			x,y, h = ice[0], ice[1], ice[2]
			area[x][y] = copy.deepcopy(h)
		#print(f"After melting {iceberg=}")

		# 얼음이 완전히 녹으면 iceberg 배열에서 뺀다. 반복문 조건이 iceberg 배열이 빌때까지 이므로.		
		i=0
		while i < len(iceberg):
			h = iceberg[i][2]
			if h == 0:
				iceberg.pop(i)
			else:
				i += 1
						
		#print(f"After pop {iceberg=}")
		year += 1

		visited = [[0 for _ in range(col)] for _ in range(row)]
		block_count = count_iceberg_blocks(area, iceberg, visited)
		
		# 덩어리가 2개 이상인 경우
		if block_count > 1:
			return year
		# 얼음이 녹을때까지 2 덩어리 이상으로 안 나뉘는 경우
		elif not iceberg and block_count <= 1:
			return 0			
					
	return year


if __name__ == "__main__":
	print(main())

