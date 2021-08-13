from collections import deque
import sys

def bfs():
  dx=[1,-1,0,0]
  dy=[0,0,1,-1]
  queue=deque()
  queue.append([0,0,1])
  visited[0][0][1]=1
  
  while queue:
    x,y,z=queue.popleft()
    if x==n-1 and y==m-1:
      return visited[x][y][z]
    for i in range(4):
      nx=x+dx[i]
      ny=y+dy[i]
      if 0<=nx<n and 0<=ny<m:
        if graph[nx][ny]==1 and z==1:
          visited[nx][ny][0] = visited[x][y][1]+1
          queue.append([nx,ny,0])
        elif graph[nx][ny]==0 and visited[nx][ny][z]==0:
          visited[nx][ny][z] = visited[x][y][z]+1
          queue.append([nx,ny,z])
  return -1

input=sys.stdin.readline
n,m=map(int, input().split())
graph=[]
for i in range(n):
  graph.append(list(map(int, list(input().strip()))))
  
visited=[[[0]*2 for _ in range(m)] for _ in range(n)]

print(bfs())
