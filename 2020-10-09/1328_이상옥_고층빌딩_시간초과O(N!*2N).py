from itertools import permutations as P

N=int(input())
dpL=[0]*(N+1)
dpR=[-101]*(N+1)
L,R=map(int, input().split())
cnt=0
for p in P(range(1,N+1),N):
    L_idx,n=0,0
    for i in p:
        if i>n:
            n=i
            L_idx+=1
    R_idx,n=0,0
    for i in p[::-1]:
        if i>n:
            n=i
            R_idx+=1
    if L==L_idx and R==R_idx: cnt+=1

print(cnt%1000000007)
