import sys
sys.setrecursionlimit(1500)

sys.stdin = open("input/2533.txt")

N = int(input())

friends = [None] * (N+1)
dp = [[0] * 2 for _ in range(N+1)]

for n in range(N-1):
    u, v = map(int, input().split())
    if friends[u] == None:
        friends[u] = []
        friends[u].append(v)
    else:
        friends[u].append(v)
# print(friends)

def dfs(current, is_early):
    visited[current][is_early] = True
    if friends[current] == None: # 리프노드에 도달
        if is_early:
            dp[current][is_early] = 1
            return dp[current][is_early]
        else:
            dp[current][is_early] = 0
            return dp[current][is_early]
    if is_early:
        dp[current][is_early] = 1
    for idx, child in enumerate(friends[current]):
        if(is_early == False): # 자신이 얼리어답터가 아니면 자식노드가 얼리 어답터인 경우만 가져옴
            dp[current][is_early] += dfs(child, True) if not visited[child][True] else dp[child][True]
        else:
            dp[current][is_early] += min(
                dfs(child, True) if not visited[child][True] else dp[child][True],
                dfs(child, False) if not visited[child][False] else dp[child][False]
            )
    return dp[current][is_early]

visited = [[False] * 2 for _ in range(N+1)]

dfs(1, True)
dfs(1, False)

# print(dp)

print(dp[1][0] if dp[1][0] > dp[1][1] else dp[1][1])
