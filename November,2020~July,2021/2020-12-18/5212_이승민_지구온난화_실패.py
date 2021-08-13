# 지구 온난화

n, m = list(map(int, input().split()))
g = [list(map(str, input())) for _ in range(n)]
di = [1, -1, 0, 0]
dj = [0, 0, 1, -1]

def solution():
    s = ""
    visited = [[1 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        for j in range(m):
            cnt = 0
            if visited[i][j] == 'X':
                visited[i][j] = 0
            for k in range(4):
                if visited[i]:
                    ii = i + di[k]
                    jj = j + dj[k]
                    if g[ii][jj] == '.':
                        cnt += 1
                    if cnt >= 3:
                        g[ii][jj] = '.'      
            
    for i in range(n):
        lcnt = 0
        rcnt = 0
        if g[i][0] == '.':
            lcnt += 1
        if g[i][n - 1] == '.':
            rcnt += 1
        if lcnt == n:
            
        if g[i:n].count('.') == 10:
            continue
        if cnt >= 

solution()

        