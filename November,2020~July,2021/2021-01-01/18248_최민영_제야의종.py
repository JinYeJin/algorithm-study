# 먼저 온다고 가까이 서있는 다고 보장 못함
# 그렇기 때문에 예외를 처리하기 위해서는 순서가 어느상황이든간에 서로 듣고, 못듣고 하는 경우는 no가 출력
# i번째 애가 x번은 듣고, y번은 못듣고, i+1애가 x번은 못듣고 y번은 듣는 경우
n, m = map(int, input().split())
people = list()
for _ in range(n):
    people.append(list(map(int, input().split())))

def solution():
    i, j = 0, 1
    while i < n-1:
        while j < n:
            check1, check2 = True, True
            for k in range(m):
                if people[i][k] < people[j][k]:
                    check1 = False
                if people[i][k] > people[j][k]:
                    check2 = False
                if check1 is False and check2 is False:
                    return False
            j += 1
        i += 1
    return True

result = solution()
if result is True:
    print("YES")
else:
    print("NO")
    
# for loop는 시간초과
def solution():
    for i in range(0, n-1, 1):
        for j in range(1, n, 1):
            check1, check2 = True, True
            for k in range(m):
                if people[i][k] < people[j][k]:
                    check1 = False
                if people[i][k] > people[j][k]:
                    check2 = False
                if check1 is False and check2 is False:
                    return False
    return True
