n, m, p = map(int, input().split())

arr = [(False, 0)] * n

answer = 1

for i in range(p):
    false_cnt = 0
    for j in range(n):
        if arr[j][0] == False:
            false_cnt += 1
        if arr[j][1] != 0:
            arr[j][1] -= 1
        if arr[j][1] == 0:
            arr[j][0] = False
    answer *= false_cnt
    arr[i][0] = True
    arr[i][1] = m
    
print(answer)