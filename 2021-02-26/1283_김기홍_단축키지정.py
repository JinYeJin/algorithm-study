n = int(input())

words = []

for i in range(n):
    words.append(list(input().split()))

d = {}
result = []

for i, word_list in enumerate(words):
    option = False
    for j, word in enumerate(word_list):
        if word[0].lower() not in d:
            d[word[0].lower()] = 1
            words[i][j] = "[" + word[:1] + "]" + word[1:]
            option = True
            break
    if not option:
        for j, word in enumerate(word_list):
            for k, ch in enumerate(word):
                if ch.lower() not in d:
                    d[ch.lower()] = 1
                    words[i][j] = word[:k] +"[" + word[k:k + 1] + "]" + word[k + 1:]
                    option = True
                    break
            if option:
                break

for word_list in words:
    tmp = ""
    for word in word_list:
        tmp += word + " "
    print(tmp[:-1])

