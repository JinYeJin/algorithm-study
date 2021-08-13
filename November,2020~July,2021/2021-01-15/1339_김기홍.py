n = int(input())

words = []
alpha = [0] * 26
result = 0
number = 9

for _ in range(n):
    words.append(input())

for word in words:
    i = 0
    for ch in word[::-1]:
        idx = ord(ch) - 65
        alpha[idx] += 10 ** i
        i += 1

alpha.sort(reverse=True)

for i in range(26):
    if alpha[i] == 0:
        break
    result += alpha[i] * number
    number -= 1

print(result)



