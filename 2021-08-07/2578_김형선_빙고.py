board = [list(map(int, input().split())) for _ in range(5)]
answers = [list(map(int, input().split())) for _ in range(5)]

def find_bingo(answer, board):
    bingo_count = 0
    for y in range(5):
        for x in range(5):
            if board[y][x] == answer:
                board[y][x] = 0
                bingo_count = count_bingo(x, y, board)
                break
    return bingo_count

def count_bingo(target_x, target_y, board):
    count = 1
    for x in range(5):
        if board[target_y][x] != 0:
            count -= 1
            break
    count += 1
    for y in range(5):
        if board[y][target_x] != 0:
            count -= 1
            break
    
    if target_y == target_x:
        count += 1
        for i in range(5):
            if board[i][i] != 0:
                count -= 1
                break
    if target_y + target_x == 4:
        count += 1
        for i in range(5):
            if board[i][4 - i] != 0:
                count -= 1
                break
    return count    

count = 0
total_bingo_count = 0
for y in range(5):
    if (total_bingo_count >= 3):
        break
    for x in range(5):
        count += 1
        total_bingo_count += find_bingo(answers[y][x], board)
        if (total_bingo_count >= 3):
            break
print(count)
