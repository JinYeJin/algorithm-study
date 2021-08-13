d = {}
n = int(input())

answer = ""
p = 0
result = [0] * 32768
sentence = ""

def compile(idx):
    global answer, p, result, d, sentence
    ch = sentence[idx]
    if ch == ">":
        p = p + 1 if p != 32767 else 0
    if ch == "<":
        p = p - 1 if p != 0 else 32767
    if ch == '+':
        result[p] = result[p] + 1 if result[p] != 255 else 0
    if ch == '-':
        result[p] = result[p] - 1 if result[p] != 0 else 255
    if ch == '.':
        answer += chr(result[p])
    if ch == '[':
        return d[idx] + 1 if result[p] == 0 else idx + 1
    if ch == ']':
        return d[idx] if result[p] != 0 else idx + 1
    return idx + 1

for i in range(1, n + 1):
    answer = ""
    sentence = ""
    array = []
    st = []
    d.clear()
    p = 0
    result = [0] * 32768
    while True:
        tmp = input()
        tmp = tmp.replace(" ", "")
        if tmp == "end":
            break
        idx = tmp.find("%")
        if idx != -1:
            array.append(tmp[:idx])
        else:
            array.append(tmp)

    sentence = "".join(array)
    isunder = False
    for j, ch in enumerate(sentence):
        if ch == "[":
            st.append(j)
        elif ch == "]":
            try:
                idx = st.pop()
                d[j] = idx
                d[idx] = j
            except:
                isunder = True
                break
    if st or isunder:
        print(f"PROGRAM #{i}:")
        print("COMPILE ERROR")
    else:
        pos = 0
        while pos < len(sentence):
            pos = compile(pos)
        print(f"PROGRAM #{i}:")
        print(answer)
