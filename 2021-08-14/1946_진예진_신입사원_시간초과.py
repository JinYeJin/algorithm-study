
import sys
sys.stdin = open("input/1946.txt")

T = int(input())

for t in range(T):
    N = int(input())
    scores = []
    count = 1

    for n in range(N):
        temp = list(map(int, input().split()))
        scores.append(temp)
    scores.sort(key=lambda x : x[0])

    for index, s in enumerate(scores):
        if index == 0: continue
        if s[1] < scores[index-1][1]:
            # print(s, scores[index-1])
            count += 1

    print(count)
