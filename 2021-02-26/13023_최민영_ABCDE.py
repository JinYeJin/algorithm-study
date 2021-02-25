import sys
from collections import defaultdict
input = sys.stdin.readline
n, m = map(int, input().split())
# 그래프에 담아놓고 사용
graph = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    # 친구는 단방향이 아닌 양방향
    graph[a].append(b)
    graph[b].append(a)
visited = [False] * n
# dfs
def search(cnt, node):
    global visited
    # 5개가 서로 친구여야하니까 만족한다면 1을 출력하고 종료
    if cnt == 5:
        print(1)
        exit(0)
    # 연결된 친구를 넣어보며 확인
    for vertex in graph[node]:
        if visited[vertex] is False:
            # 순열문제처럼 방문한 곳은 다시 방문하지 않게 하기 위해 True 처리
            visited[vertex] = True
            # cnt 추가해서 그 vertex부터 재귀
            search(cnt + 1, vertex)
            # 방문했던 곳 다시 해제 처리
            visited[vertex] = False
# 어디부터 시작해야할지 모르니 0부터 시작
for i in range(n):
    # i는 미리 넣고 시작
    visited[i] = True
    search(1, i)
    # 끝났을 경우 종료
    visited[i] = False
print(0)