import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m = map(int, input().split())

parent = [0] * (n + 1)

for i in range(1, n + 1):
    parent[i] = i

for _ in range(m):
    op, a, b = map(int, input().split())
    if op == 0:
        union_parent(parent, a, b)
    else:
        if find_parent(parent, a) != find_parent(parent, b):
            print("NO")
        else:
            print("YES")

