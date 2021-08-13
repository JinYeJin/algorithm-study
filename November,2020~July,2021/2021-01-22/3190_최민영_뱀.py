import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
m = [[0] * n for _ in range(n)]
a = int(input())
apple = [tuple(map(int, input().split())) for _ in range(a)]
d = int(input())
di = {
    # 직진 방향, 좌, 우
    (0, 1): [(-1, 0), (1, 0)],
    (1, 0): [(0, 1), (0, -1)],
    (0, -1): [(1, 0), (-1, 0)],
    (-1, 0): [(0, -1), (0, 1)]
}
direction = deque()
for _ in range(d):
    c, dl = input().split()
    dl = 0 if dl == "L" else 1
    direction.append((int(c), dl))
for x, y in apple:
    m[x - 1][y - 1] = 1
# 맨 앞과 맨 마지막을 신경 써야 함
q = deque([(0, 0)])
cnt = 0
next_cnt = direction.popleft()
# 방향은 우두머리만 알고 있으면 됨
now_dir = (0, 1)
while len(q) > 0:
    now_x, now_y = q[0]
    add_x, add_y = now_dir
    # 다음 좌표
    next_x, next_y = now_x + add_x, now_y + add_y
    cnt += 1
    if next_x < 0 or next_x >= n or next_y < 0 or next_y >= n or (next_x, next_y) in q:
        break
    q.appendleft((next_x, next_y))
    if m[next_x][next_y] == 1:
        m[next_x][next_y] = 0
    else:
        q.pop()
    if cnt == next_cnt[0]:
        # 0 or 1
        now_dir = di[now_dir][next_cnt[1]]
        if len(direction) > 0:
            next_cnt = direction.popleft()

print(cnt)
