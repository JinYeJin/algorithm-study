# import sys
# input = sys.stdin.readline
from collections import defaultdict
from collections import deque
n = int(input())
indegree = defaultdict(list)
outdegree = defaultdict(list)
for _ in range(n - 1):
    a, b = map(int, input().split())
    outdegree[a].append(b)
    indegree[b].append(a)
q = deque()
arr = [0] * (n + 1)
arr[0] = -1
for i in range(n + 1):
    if len(indegree[i]) == 0:
        q.append(i)
        arr[i] += 1
while q:
    now = q.popleft()
    for i in outdegree[now]:
        q.append(i)
        arr[i] += 1
result = []
for i in arr:
    if i >= 2:
        result.append(i)
if len(result) == 0:
    print(-1)
else:
    for i in result:
        print(i)
