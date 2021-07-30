from collections import deque
answer=0
N, M = map(int,input().split())
know = set(input().split()[1:])
q = deque([i for i in range(M)])
party=[]
for _ in range(M):
    party.append(set(input().split()[1:]))
while 1:
    size=len(q)
    for _ in range(size):
        i = q.popleft()
        if len(know & party[i]) == 0:
            q.append(i)
        else:
            know|=party[i]
    if len(q)==size:
        break
print(len(q))
