import sys

input=sys.stdin.readline
n,m=map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

for k in range(n):
  for i in range(n):
    for j in range(n):
      if graph[i][j]>graph[i][k]+graph[k][j]:
        graph[i][j]=graph[i][k]+graph[k][j]

for i in range(m):
  x,y,z=map(int, input().split())
  if graph[x-1][y-1]<=z:
    print("Enjoy other party")
  else:
    print("Stay here")
