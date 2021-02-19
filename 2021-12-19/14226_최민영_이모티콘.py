# https://kyu9341.github.io/algorithm/2020/03/11/algorithm14226/
# https://developingbear.tistory.com/138
# https://devbelly.tistory.com/108
# 이모티콘 s개 생성
# 3가지 연산 이용
# bfs 이용 => visited를 이모티콘 방문 여부 2차원 배열 => 이모티콘의 수 와 클립보드에 저장된 이모티콘의 갯수를 이용
from collections import deque
s = int(input())
q = deque()
# visited[이모티콘의 수][클리보드의 이모티콘 수]
visited = [[False] * 1001 for _ in range(1001)]
visited[1][0] = True
# 이모티콘의 수, 클립보드의 수, 시간
q.append((1, 0, 0))
while q:
    e, clip, t = q.popleft()
    if e == s:
        print(t)
        exit(0)

    if 0 < e < 1001:
        if visited[e][e] is False:
            visited[e][e] = True
            q.append((e, e, t + 1))
        # clip이 0 이상 조건이 필요없음 어차피 위에서 e가 0보다 큰걸로 조건 수행했으므로
        if e + clip < 1001 and visited[e + clip][clip] is False:
            visited[e + clip][clip] = True
            q.append((e + clip, clip, t + 1))
        # e가 1000을 넘을때만 수행하는 것이 아닌 모든 경우에 대해서 탐색을 하기 위해서 e에 대한 조건을 걸지 않음
        if visited[e - 1][clip] is False:
            visited[e - 1][clip] = True
            q.append((e - 1, clip, t + 1))
