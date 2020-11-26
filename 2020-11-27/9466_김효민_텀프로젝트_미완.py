#미완이지만 일단 올립니다.ㅜㅜ

import sys

def dfs(v):
  visited[v]=1
  stack.append(v)
  x=s[v]
  if visited[x]:
    if x in stack:
      #미완성
    return
  else:
    dfs(x)

input=sys.stdin.readline
t=int(input())
for _ in range(t):
  n=int(input())
  s=[0]+list(map(int, input().split()))
  visited=[1]+[0]*n
  result=[]
  for i in range(1,n+1):
    if not visited[i]:
      stack=[]
      dfs(i)
  print(n-len(result))
