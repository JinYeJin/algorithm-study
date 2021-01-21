# 폴짝폴짝
# 시간 : 3시간
# 구현 아이디어 : dfs방식으로 점프할 수 있는 지점을 순회하면서 
# abs( b(도착지점) - round(현재위치) ) % bridge[round](현재위치에서 점프할 수 있는 거리) == 0 방식

import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline
n = int(input())
bridge = [0] + list(map(int, input().split()))
a, b = map(int, input().split())
visited = [0] * 10001
dp = [10001] * n
    
def dfs(round, cnt):
    visited[round] = 1
    if abs(b - round) >= bridge[round] and abs(b - round) % bridge[round] == 0:
        dp[round] = cnt + 1
        return
    else:
        for i in range(1, n):
            if not visited[i]:
                if abs(i - round) >= bridge[round] and abs(i - round) % bridge[round] == 0:
                    dfs(i, cnt + 1)

def solution():
    if a == b:
        print(0)
        return
    dfs(a, 0)
    ans = min(dp)
    if ans == 10001:
        print(-1)
    else:
        print(ans)
solution()


# def bfs(i, cnt):
#     q = deque()
#     q.append(i)
#     while q:
#         round = q.pop()
#         cnt += 1
#         d1 = abs(b - round)
#         if d1 >= bridge[round] and d1 % bridge[round] == 0:
#             dp[round] = cnt
#         else:
#             for i in range(1, n):
#                 if not visited[i]:
#                     d2 = abs(i - round) 
#                     if d2 >= bridge[round] and d2 % bridge[round] == 0:
#                         visited[i] = 1
#                         q.append(i)

# Test Case 

# 5
# 3 4 8 2 1
# 1 5

# 답 : -1

# 1
# 1
# 1 1

# 답 : 0

# 8
# 4 4 6 1 3 2 5 4
# 2 3

# 답 : 3