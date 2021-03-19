data = input()
notDot = 0
result = ""
for i in range(len(data)):
    if data[i] != '.':
        notDot += 1
    elif data[i] == '.':
        result += '.'
        if notDot % 2 == 1:
            print(-1)
            exit(0)
        notDot = 0
        continue
    if notDot == 4:
        if len(result) >= 2:
            result = result[:-2]
        result += "AAAA"
        notDot = 0
        continue
    elif notDot == 2:
        result += "BB"
if len(result) != len(data):
    print(-1)
else:
    print(result)
