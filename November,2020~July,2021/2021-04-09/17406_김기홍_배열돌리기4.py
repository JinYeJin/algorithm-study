from collections import deque
from copy import deepcopy

INF = int(1e9)

n, m, k = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]
pos = []
for _ in range(k):
    r, c, s = map(int, input().split())
    pos.append([r - 1, c - 1, s])


dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def dfs(cnt):
    global answer
    if cnt == k:
        c_q = deepcopy(q)
        answer = min(answer, rotate(c_q))
        return
    for i in range(k):
        if select[i]:
            continue
        select[i] = 1
        q.append(pos[i])
        dfs(cnt + 1)
        select[i] = 0
        q.pop()


def rotate(q):
    c_board = deepcopy(board)
    while q:
        r, c, s = q.popleft()
        lx, ly, rx, ry = r - s, c - s, r + s, c + s
        while True:
            if lx >= rx or ly >= ry:
                break
            idx = 0
            r, c, before = lx, ly, c_board[lx][ly]
            while True:
                nx = r + dx[idx]
                ny = c + dy[idx]
                if not lx <= nx <= rx or not ly <= ny <= ry:
                    idx += 1
                    continue
                temp = c_board[nx][ny]
                c_board[nx][ny] = before
                before = temp
                r, c = nx, ny
                if r == lx and c == ly:
                    lx += 1
                    ly += 1
                    rx -= 1
                    ry -= 1
                    break
    result = INF
    for row in c_board:
        result = min(result, sum(row))
    return result


select = [0 for _ in range(k)]
answer = INF
q = deque()
dfs(0)
print(answer)
