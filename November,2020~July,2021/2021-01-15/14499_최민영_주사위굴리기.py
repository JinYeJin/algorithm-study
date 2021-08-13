import sys
input = sys.stdin.readline
n, m, x, y, order_number = map(int, input().split())
maap = list()
for _ in range(n):
    maap.append(list(map(int, input().split())))
order_list = list(map(int, input().split()))
dice = [0 for _ in range(6)]
mv = ((0, 1), (0, -1), (-1, 0), (1, 0))
# 4개의 원소만 리턴
def move_horizon(dice):
    # 2, 5 번째 원소는 건들지 않음 => 1, 4
    return_dice = list()
    for d in range(6):
        if d == 1 or d == 4:
            continue
        else:
            return_dice.append(dice[d])
    return return_dice
# 4개의 원소만 리턴
def move_vertical(dice):
    # 3, 4 번째 원소는 건들지 않음 => 2, 3
    return_dice = list()
    for d in range(6):
        if d == 2 or d == 3:
            continue
        else:
            return_dice.append(dice[d])
    return return_dice
# 원소의 위치를 변경해서 리턴
def east_north(inner_dice):
    return [inner_dice[2], inner_dice[0], inner_dice[3], inner_dice[1]]
def west_south(inner_dice):
    return [inner_dice[1], inner_dice[3], inner_dice[0], inner_dice[2]]
def check_direction(in_dice, order_number):
    if order_number % 2 == 0:
        return east_north(in_dice)
    else:
        return west_south(in_dice)

def solution(i, j, order):
    global dice
    result_list = list()
    order_pos = 0
    pos_x, pos_y = i, j
    while order_pos < len(order):
        now_order = order[order_pos]
        after_x, after_y = pos_x + mv[now_order-1][0], pos_y + mv[now_order-1][1]
        if not 0 <= after_x < n or not 0 <= after_y < m:
            order_pos += 1
            continue
        pos_x, pos_y = after_x, after_y
        pos_number = maap[pos_x][pos_y]

        # 동서로 이동 => horizon
        if now_order == 1 or now_order == 2:
            change_dice = move_horizon(dice)
            tmp_dice = check_direction(change_dice, now_order)
            for k in range(6):
                if k == 1 or k == 4:
                    continue
                dice[k] = tmp_dice.pop(0)
        # 남북으로 이동 => vertical
        else:
            change_dice = move_vertical(dice)
            tmp_dice = check_direction(change_dice, now_order)
            for k in range(6):
                if k == 2 or k == 3:
                    continue
                dice[k] = tmp_dice.pop(0)
        if pos_number == 0:
            maap[pos_x][pos_y] = dice[5]
        else:
            dice[5] = maap[pos_x][pos_y]
            maap[pos_x][pos_y] = 0
        order_pos += 1
        result_list.append(dice[0])
    return result_list
result = solution(x, y, order_list)
for i in result:
    print(i)
    
-----

import sys
input = sys.stdin.readline
n, m, x, y, order_number = map(int, input().split())
maap = list()
for _ in range(n):
    maap.append(list(map(int, input().split())))
order_list = list(map(int, input().split()))
dice = [0 for _ in range(6)]
mv = ((0, 1), (0, -1), (-1, 0), (1, 0))
def solution(i, j, order):
    global dice
    result_list = list()
    order_pos = 0
    pos_x, pos_y = i, j
    while order_pos < len(order):
        now_order = order[order_pos]
        after_x, after_y = pos_x + mv[now_order-1][0], pos_y + mv[now_order-1][1]
        if not 0 <= after_x < n or not 0 <= after_y < m:
            order_pos += 1
            continue
        pos_x, pos_y = after_x, after_y
        pos_number = maap[pos_x][pos_y]
        # 동
        if now_order == 1:
            tmp = [dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]]
            dice = tmp
        # 서
        elif now_order == 2:
            tmp = [dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]]
            dice = tmp
        # 남
        elif now_order == 3:
            tmp = [dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]]
            dice = tmp
        # 북
        else:
            tmp = [dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]]
            dice = tmp
        if pos_number == 0:
            maap[pos_x][pos_y] = dice[5]
        else:
            dice[5] = maap[pos_x][pos_y]
            maap[pos_x][pos_y] = 0
        order_pos += 1
        result_list.append(dice[0])
    return result_list
result = solution(x, y, order_list)
for i in result:
    print(i)
