# 빙산
# 구현 아이디어 : DFS 방식으로 원소 하나마다 주변 0만큼 값을 빼주고
# 주변에 0 밖에 없으면 분리 개수를 증가, 분리 횟수가 2회 이상이면 끝내기
# 또한 한 번에 모두 녹을 때의 종료 조건은 0의 개수로 파악
# 종료 조건 및 2개 이상의 덩어리일 때의 처리를 모르겠습니다....

n, m = list(map(int, input().split())) # 행 열
map = [list(map(int, input().split())) for _ in range(n)]
dy = [1, -1, 0, 0] # 행
dx = [0, 0, 1, -1] # 열
zero = [0] # 해당 원소 기준 사방으로 0이 있는지 확인
cnt = [0] # 전체 0의 개수 -> 끝내는 조건
div = [0] # 분리되는 개수
ans = [0] # 시행 횟수

def dfs(y, x):
    if zero[0] == 4:
        div[0] += 1
        zero[0] = 0
    if map[y][x] == 0:
        return
    zero[0] = 0
    for i in range(4):
        y1 = y + dy[i]
        x1 = x + dx[i]
        if map[y1][x1] == 0:
            zero[0] += 1
            if map[y][x] != 0:
                map[y][x] -= 1
            continue
        elif map[y1][x1] != 0:
            dfs(y1, x1)
    return

while 1:
    if ans[0] > 1 and div[0] > 1:
        print(ans[0])
        break
    cnt[0] = 0
    for i in range(n):
        for j in range(m):
            if map[i][j] != 0:
                dfs(i, j)
            else:
                cnt[0] += 1
    if cnt[0] == n * m:
        print(0)
        break
    ans[0] += 1