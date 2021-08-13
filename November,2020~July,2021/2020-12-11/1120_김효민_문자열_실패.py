import sys

input=sys.stdin.readline
a,b = input().split()
c1=0
c2=0
for i in range(len(a)):
  if a[i]!=b[i]:
    c1+=1
    
a=a[::-1]
b=b[::-1]

for i in range(len(a)):
  if a[i]!=b[i]:
    c2+=1

print(min(c1, c2))
