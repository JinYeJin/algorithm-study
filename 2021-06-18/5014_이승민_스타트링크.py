# -*- coding: utf-8 -*-

# 스타트링크
# 시간 : 30분
# 구현 아이디어 : bfs -> 위, 아래로 가는 두가지 경우를 쭉 가보면서 제일 먼저 도착하는 횟수를 출력
# 비슷한 문제 : 숨바꼭질

import sys
from collections import deque
input = sys.stdin.readline
f, s, g, u, d = map(int, input().split())
d = [u, -d] # 방향

# 도착지점이 시작지점보다 낮은 곳에 있는 데 d가 0이거나 도착지점이 시작지점보다 높은 곳에 있는데 u이 0일 경우 예외처리
if (s > g and d == 0) or (s < g and u == 0):
    print("use the stairs")
    exit()

def bfs(f, s, g, u, d):
    q = deque()
    q.append([s, 0]) # 데큐에 [현재 지점, 횟수] 저장
    visited = set() # 중복으로 저장하지 않도록 set을 사용
    while q:
        s, cnt = q.pop()
        visited.add(s) # 큐에서 꺼낼 때마다 방문 체크
        # 도착지점에 도달했다면 횟수를 출력하고 프로그램 종료 -> 가장 먼저 도착한 지점이 최소 값이기 때문
        if s == g:
            print(cnt)
            exit()
        # 현재 지점(s)에서 up 또는 down 두가지 경우 실행
        for k in range(2):
            ns = s + d[k] # new start
            if ns > f or ns < 1: # 올라갔는데 총 높이보다 높아지거나 내려갔는데 0층 이하이면 넘어가기
                continue
            # 방문하지 않은 곳일 때만 visited에 층수 저장 및 큐에 [다음 지점, 횟수 + 1]을 저장
            if ns not in visited:
                visited.add(ns)
                q.append([ns, cnt + 1])
    print("use the stairs") # 도달할 수 없다면 해당 문장 출력
bfs(f, s, g, u, d)