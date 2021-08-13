# 합집합 연산과 두 원소가 같은 집합에 포함되어있는지 확인하는 연산 수행
# n은 노드 갯수
# m은 연산 횟수
from collections import deque
n, m = map(int, input().split())
cal = deque()
max = 1000002
root = [i for i in range(max)]
for _ in range(m):
    # 0일 경우, 합집합
    # 1일 경우, 찾기
    op, a, b = map(int, input().split())
    cal.append((op, a, b))

rank = [0 for i in range(max)]
def find(x):
    if root[x] == x:
        return x
    else:
        root[x] = find(root[x])
        return root[x]

# rank 가 작을수록 밑에 있음
def union(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rank[x] < rank[y]:
        root[x] = y
    else:
        root[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1

while cal:
    o, a, b = cal.popleft()
    if o == 0:
        union(a, b)
    elif o == 1:
        x = find(a)
        y = find(b)
        if x == y:
            print("YES")
        else:
            print("NO")
