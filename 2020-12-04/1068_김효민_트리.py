def dfs(root):
  global cnt
  visited[root]=1
  temp=1
  for i in range(n):
    if graph[root][i]==1 and visited[i]==0:
      temp=0
      dfs(i)
  if temp==1:
    cnt+=1

n = int(input())
parents = list(map(int, input().split()))
node = int(input())
graph = [[0]*n for _ in range(n)]
visited = [0]*n
cnt=0
for i in range(len(parents)):
  if parents[i]!=-1:
    graph[i][parents[i]]=1
    graph[parents[i]][i]=1
  else:
    root=i
for i in range(n):
  graph[i][node]=0
  graph[node][i]=0
dfs(root)
if node==root:
  print(0)
else:
  print(cnt)
