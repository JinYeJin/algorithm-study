n, k = map(int, input().split())
answer = 0

def dfs(key, ch_cnt):
    global answer
    if ch_cnt == k - 5:
        word_cnt = 0
        for word in words:
            for ch in word:
                if ch not in d.keys():
                    break
            else:
                word_cnt += 1
        answer = max(answer, word_cnt)
        return

    for i in range(ord(key), ord('z') + 1):
        if chr(i) not in d.keys():
            d[chr(i)] = True
            dfs(chr(i), ch_cnt + 1)
            del d[chr(i)]
    
d = {}
for ch in ["a", "c", "n", "t", "i"]:
    d[ch] = True

words = []

for _ in range(n):
    tmp = input()
    words.append(tmp[3:-4])
    
if k < 5:
    answer = 0
elif k == 26:
    answer = n
else:
    dfs('a', 0)

print(answer)