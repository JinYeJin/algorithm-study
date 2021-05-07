def rotate(l, n):
    return l[n:] + l[:n]

temp = input()

N, K = map(int, temp.split())

con = [0] * (2*N)
robots = [False] * (2*N)
temp = input()

con = list(map(int, temp.split()))
len_belt = 2*N
num_zero = 0
count = 0


while(num_zero < K):
    count += 1
    # step1
    robots[N-1] = False
    con = rotate(con, -1)

    # print('con')
    # for n in range(len_belt):
    #     print(con[n], end=' ')
    # print()



    # step 2
    for n in range(N-1, -1, -1):
        if (con[n] > 0) and (robots[n] == False):
            con[n] -= robots[n-1] # 로봇이 있는 경우에만 내구도 감소
            robots[n] = robots[n-1]
            robots[n-1] = False

    # step 3
    if con[0] > 0:
        robots[0] = True
        con[0] -= 1

    # step 4
    num_zero = 0
    # print('con2')
    for n in range(len_belt):
        # print(con[n], end=' ')
        if con[n] == 0: num_zero += 1

    # print()
    # 
    # print('robots')
    # for n in range(len_belt):
    #     print(robots[n], end=' ')
    # print()
    # 
    # print()
    # print(count)
    # print('----')

print(count)
