import sys

def divide(x,y,n):
  global blue,white
  color = paper[x][y]
  for i in range(x,x+n):
    for j in range(y,y+n):
      if color!=paper[i][j]:
        divide(x,y,n//2)
        divide(x,y+n//2,n//2)
        divide(x+n//2,y,n//2)
        divide(x+n//2,y+n//2,n//2)
        return
  if color==1:
    blue+=1
    return
  else:
    white+=1
    return

input=sys.stdin.readline
n=int(input())
paper=[list(map(int, input().split())) for _ in range(n)]
blue,white = 0,0

divide(0,0,n)
print(white)
print(blue)
