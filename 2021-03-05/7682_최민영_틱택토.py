def check(st):
    r = []
    # 가로
    for i in range(0, 7, 3):
        if st[i] != "." and st[i] == st[i + 1] and st[i + 1] == st[i + 2]:
            r.append(st[i])
    # 세로
    for i in range(3):
        if st[i] != "." and st[i] == st[i + 3] and st[i + 3] == st[i + 6]:
            r.append(st[i])
    # 대각선
    if st[0] != "." and st[0] == st[4] and st[4] == st[8]:
        r.append(st[0])
    if st[2] != "." and st[2] == st[4] and st[4] == st[6]:
        r.append(st[2])
    return r

while True:
    tik = input()
    if tik == "end":
        exit(0)
    x, o = 0, 0
    for i in tik:
        if i == 'X':
            x += 1
        elif i == 'O':
            o += 1
    result = check(tik)
    # 9개 모두 입력되었지만 승리 없을 경우
    if "X" not in result and "O" not in result and x == 5 and o == 4:
        print("valid")
    # o가 승리한 경우
    elif "X" in result and "O" not in result and x == o + 1:
        print("valid")
    # x가 승리한 경
    elif "O" in result and "X" not in result and x == o:
        print("valid")
    else:
        print("invalid")
