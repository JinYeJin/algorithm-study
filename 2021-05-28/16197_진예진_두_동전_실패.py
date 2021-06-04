from queue import Queue
import sys


dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def out_boundary(c):
    return board[c[0]][c[1]] == 'x'

def move(q):
    global answer
    c = q.get()
    # print(c)

    a = c['a']
    b = c['b']

    if c['move'] > 10: return True

    for d in range(4):
        na = (a[0] + dy[d], a[1] + dx[d])
        nb = (b[0] + dy[d], b[1] + dx[d])
        # print('na', na, 'nb', nb)

        bound_a = out_boundary(na) # 밖에 나갈경우 True
        bound_b = out_boundary(nb)

        if board[na[0]][na[1]] == '#': # 벽에 닿을 경우 이동 안함
            na = a
        if board[nb[0]][nb[1]] == '#':
            nb = b

        if bound_a ^ bound_b: # 둘 중 하나만 나가야 함
            # print("out of boundary")
            answer = c['move'] + 1
            return True
        elif bound_a and bound_b: # 둘 다 나간경우
            continue

        q.put({'a': na, 'b': nb, 'move': c['move']+1 })
    return q


N, M = map(int, input().split())

board = []

a = None
b = None
flag = True

# visited_a = [[False] * (M+2) for _ in range(N+2)]
# visited_b = [[False] * (M+2) for _ in range(N+2)]

# input
board.append(['x' for _ in range(M+2)])

for n in range(N):
    temp = input()
    temp_list = []
    temp_list.append('x')
    for m in range(M):
        temp_list.append(temp[m])
        if temp[m] == 'o':
            if flag:
                a = (n+1, m+1)
                flag = False
            else: b = (n+1, m+1)
    temp_list.append('x')
    board.append(temp_list)

board.append(['x' for _ in range(M+2)])

# print(board, a, b)

q = Queue()

q.put({'a': a, 'b': b, 'move': 0})

answer = 0

while(True):
    q = move(q)
    if q == True:
        break

print(answer if answer < 1 or answer < 11 else -1)
