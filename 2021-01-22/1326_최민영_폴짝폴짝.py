import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
j = list(map(int, input().split()))
a, b = map(int, input().split())
def solution(s, e):
    visited = [False] * n
    f = False
    cnt = 0
    q = deque([(s, 0)])
    while q:
        now, n_cnt = q.popleft()
        if now == e:
            f = True
            cnt = n_cnt
            break
        if visited[now] is True:
            continue
        visited[now] = True
        # 오른쪽으로 움직임 양수 배
        i = 1
        while now + j[now] * i < n:
            next = now + j[now] * i
            if visited[next] is False:
                q.append((next, n_cnt + 1))
            i += 1
        # 왼쪽으로 움직임 음수배
        # 자연수여도 음수의 배수만큼 이동 가능
        k = 1
        while now - (j[now] * k) >= 0:
            next = now - (j[now] * k)
            if visited[next] is False:
                q.append((next, n_cnt + 1))
            k += 1
    if f is False:
        cnt = -1
    return cnt
print(solution(a-1, b-1))
