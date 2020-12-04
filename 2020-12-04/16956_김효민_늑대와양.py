import sys

input = sys.stdin.readline
r, c = map(int, input().split())
graph = [[i for i in input().strip()] for _ in range(r)]

dx = [1,0,-1,0]
dy = [0,-1,0,1]
temp = 0
for i in range(r):
  for j in range(c):
    if graph[i][j]=='W':
      for k in range(4):
        nx = i+dx[k]
        ny = j+dy[k]
        if nx<0 or nx>=r or ny<0 or ny>=c:
          continue
        if graph[nx][ny]=='S':
          temp = 1
          break
    elif graph[i][j]=='S':
      continue
    else:
      graph[i][j]='D'

if temp:
  print(0)
else:
  print(1)
  for i in graph:
    print(''.join(i))
