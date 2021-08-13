import re
sound = input()
def solution(str):
    check = True
    sound = str
    try:
        regx = re.compile('(100+1+|01)+')
        result = regx.fullmatch(sound)
        s, e = result.start(), result.end()

        parseData = sound.replace(sound[s:e],"")
        if len(parseData) > 0:
            check = False
    except:
        check = False
    if check:
        return "SUBMARINE"
    else:
        return "NOISE"

result = solution(sound)
print(result)

