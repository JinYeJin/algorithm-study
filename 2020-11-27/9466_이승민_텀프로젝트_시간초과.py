# 텀 프로젝트

import sys
sys.setrecursionlimit(10000000)

n = int(input())
idx = [0 for _ in range(1)] # 학생 번째
sum = [0 for _ in range(1)] # 팀에 속한 학생 수
answer = [0 for _ in range(n)] # 답

def dfs(k, past, d):
    # 길이가 stu길이보다 크거나 같으면 리턴
    if k >= len(stu) or d >= len(stu):
        return
    # 깊이가 0이면 먼저 처음이 몇번째 학생인지 저장
    if d == 0:
        idx[0] = k
    # 깊은 탐색을 하다가 자기 자신이 나왔을 때
    if d > 0 and k == idx[0]:
        sum[0] += 1 
        return
    # 재귀에서 이전 노드와 값이 같은 때
    if past == k:
        return
    d += 1 # 깊이
    past = k # 이전 노드
    # n번째 학생이 선택한 학생과 깊이를 재귀
    dfs(stu[k], past, d)
    # 만약 처음 시작 학생 번호가 나오지 않으면 리턴
    if k != idx[0]:
        return
    # 다음 학생으로 넘어감
    dfs(k + 1, 0, 0)
    return

for i in range(n):
    l = int(input())
    stu = [int(i) for i in input().split()]
    stu.insert(0, 0)
    dfs(1, 0, 0)
    answer[i] = len(stu) - 1 - sum[0] # 실제 결과값은 길이 - 1 - 팀의 속한 학생 수
    sum[0] = 0
    
for i in range(n):
    print(answer[i])

# Test Case
# 2
# 7
# 3 1 3 7 3 4 6
# 8
# 1 2 3 4 5 6 7 8

# 6
# 2 3 4 5 6 2
# output : 1

# 5
# 2 5 4 5 2
# output : 3

# 6
# 1 3 4 3 2 6
# output : 2

# 13
# 2 4 5 2 4 1 8 9 10 11 9 10 10
# output : 8

# 10
# 2 5 7 1 6 8 8 3 5 10
# output : 6

# 10
# 2 7 10 5 3 3 9 10 6 3
# output : 8

# 6
# 2 1 1 2 6 3
# output : 4