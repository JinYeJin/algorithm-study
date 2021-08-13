from collections import deque 
n, m = map(int, input().split())
area = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
distance = 0

for _ in range(n):	
	area.append(list(input()))

for r in range(n):
	for c in range(m):
		if area[r][c] == 'W':
			continue
		else: #각 정점마다 bfs진행하여 가장 긴 distance로 갱신
			visited = [[False for _ in range(m) ] for _ in range(n)]
			dis = [[0]*m for _ in range(n)]
			q = deque()
			q.append((r,c))
			visited[r][c] = True			
			while (q):
				tmp = q.popleft()
				for i in range(4):
					x = tmp[0]+dx[i]
					y = tmp[1]+dy[i]
					if 0<=x<n and 0<=y<m and visited[x][y] == False and area[x][y] == 'L':
						visited[x][y] = True
						dis[x][y] = dis[tmp[0]][tmp[1]]+1
						q.append((x, y))
						if dis[x][y] > distance:
							distance = dis[x][y]
print(distance)
	