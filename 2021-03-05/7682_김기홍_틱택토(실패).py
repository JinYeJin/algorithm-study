check = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]

isvalid = False

def dfs(game, cnt):
    global isvalid
    if cnt == 9:
        isvalid = True
        return
    
    for arr in check:
        if game[arr[0]] != '.' and game[arr[0]] == game[arr[1]] and game[arr[0]] == game[arr[1]]:
            isvalid = True
            return

    for i in range(9):
        if game[i] != '.':
            dfs(game, cnt + 1)

while True:
    isvalid = False
    game = input()
    if game == "end":
        break
    cnt = 0
    dfs(game, cnt)
        

    if isvalid:
        print("valid")
    else:
        print("invalid")
    # board = [[] for _ in range(3)]
    # for idx, ch in enumerate(game):
    #     board[idx // 3].append(ch)
    
    

    