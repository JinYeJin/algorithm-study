def solution(s):    
    pringles = []
    s = list(s)
    while (s):
        chip = s.pop()
        if pringles and pringles[-1] == chip:
            pringles.pop()
        else:
            pringles.append(chip)
    return 0 if pringles else 1

'''
알파벳은 짝수개씩 있어야한다.
짝수개여도 서로 연달아 붙어있을 수 있어야 짝지어서 제거할 수 있다.
cdcd이면 불가능하다.
순회 중간에 있는걸 날릴려고하면 효율성이 떨어진다.
그렇다면 어떻게 날리는게 효율적일것인가?
새로운 배열을 만들어서 새로 담는다?
다담기면 끝
스택 이용
'''