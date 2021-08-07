import sys
sys.stdin = open("input/2578.txt")

def bingo_check():
    global answer
    global_bingo = 0
    for r in range(5):
        bingo_count = 0
        for c in range(5):
            if xo[r][c] == True:
                bingo_count += 1
        if bingo_count >= 5:
            global_bingo += 1

    for c in range(5):
        bingo_count = 0
        for r in range(5):
            if xo[r][c] == True:
                bingo_count += 1
        if bingo_count >= 5:
            global_bingo += 1

    # 대각선 왼쪽상단
    x = 0
    y = 0
    bingo_count = 0
    for _ in range(5):
        if xo[y][x] == True:
            bingo_count += 1
        x += 1
        y += 1
    if bingo_count >= 5:
        global_bingo += 1

    # 대각선 오른쪽 상단
    x = 4
    y = 0
    bingo_count = 0
    for _ in range(5):
        if xo[y][x] == True:
            bingo_count += 1
        x -= 1
        y += 1
    if bingo_count >= 5:
        global_bingo += 1

    if global_bingo >= 3:
        # print("global_bingo", global_bingo)
        return True

    return False

bingo = []
answer = 0
xo = [[False] * 5 for _ in range(5)]

for _ in range(5):
    bingo.append(list(map(int, input().split())))

# print(bingo)

for i in range(5):
    input_numbers = input().split()

    for number in input_numbers:
        number = int(number)

        for r in range(5):
            for c in range(5):
                if bingo[r][c] == number:
                    xo[r][c] = True

        # for r in range(5):
        #     for c in range(5):
        #         print("X" if xo[r][c] == True else "_", end=" ")
        #     print()
        # print()

        answer += 1
        if bingo_check():
            # print("answer" ,answer)
            print(answer)
            exit(0)
