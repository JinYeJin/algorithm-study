n = int(input())
words = [input() for _ in range(n)]
# 단축키 저장하는 집합
shortcut = set()
# 단축키에 있는지 확인하는 함수
def check_shortcut(word):
    global shortcut
    for i in range(len(word)):
        if word[i].upper() not in shortcut and word[i] != " ":
            shortcut.add(word[i].upper())
            return word[:i] + "[" + word[i] + "]" + word[i + 1:]
    return ""

for w in words:
    w_list = w.split()
    # flag
    flag = False
    for k in range(len(w_list)):
        ws = w_list[k]
        # 단어의 첫번째 글자가 단축키로 지정되어있는지 확인
        if ws[0].upper() not in shortcut:
            p = check_shortcut(ws)
            if len(p) != 0:
                w_list[k] = p
                print(" ".join(w_list))
                flag = True
        if flag is True:
            break
        else:
            continue
    if flag is False:
        # 단어의 각 첫번째 글자들이 단축키로 지정되어있다면 전체를 돌면서 확인
        p = check_shortcut(w)
        if len(p) != 0:
            print(p)
            flag = True
    # 모든 글자가 단축키로 지정되어있을 경우
    if flag is False:
        print(w)