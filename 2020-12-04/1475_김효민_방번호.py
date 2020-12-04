import sys
import math

input = sys.stdin.readline
n=list(map(int, input().strip()))
num=[0]*10
cnt=0

for i in n:
  if i==9:
    num[6]+=1
  else:
    num[i]+=1

if num.index(max(num))==6:
  print(math.ceil(max(num)/2))
else:
  print(max(num))
