import sys

input=sys.stdin.readline
n,k=map(int, input().split())
doll=input().split()

if doll.count('1')<k:
  print(-1)
else:
  ryan=[i for i,x in enumerate(doll) if x=='1']
  print(min(ryan[i+k-1]-ryan[i]+1 for i in range(len(ryan)-k+1)))
