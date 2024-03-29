import sys
input = sys.stdin.readline
n = int(input())
testCase = [list(input().strip()) for _ in range(n)]
d = [[-1,0], [0,-1], [1,0], [0, 1]] # 북 서 남 동
ans = []
# tutle = [0, 0, 0] # 방향 i, j


for case in testCase:
    iArr = set()
    jArr = set()
    iArr.add(0)
    jArr.add(0)
    tutle = [0, 0, 0] 
    for s in case:
        if s == "F":
            if tutle[0] == 0:
                tutle[1], tutle[2] = tutle[1] + d[0][0], tutle[2] + d[0][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 1:
                tutle[1], tutle[2] = tutle[1] + d[1][0], tutle[2] + d[1][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 2:
                tutle[1], tutle[2] = tutle[1] + d[2][0], tutle[2] + d[2][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 3:
                tutle[1], tutle[2] = tutle[1] + d[3][0], tutle[2] + d[3][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
        elif s == "B":
            if tutle[0] == 0:
                tutle[1], tutle[2] = tutle[1] - d[0][0], tutle[2] - d[0][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 1:
                tutle[1], tutle[2] = tutle[1] - d[1][0], tutle[2] - d[1][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 2:
                tutle[1], tutle[2] = tutle[1] - d[2][0], tutle[2] - d[2][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
            elif tutle[0] == 3:
                tutle[1], tutle[2] = tutle[1] - d[3][0], tutle[2] - d[3][1]
                iArr.add(tutle[1])
                jArr.add(tutle[2])
        elif s == "L":
            tutle[0] = (tutle[0] + 1) % 4
        elif s == "R":
            tutle[0] = (tutle[0] - 1) % 4
    sortI = sorted(iArr)
    sortJ = sorted(jArr)
    print(sortI)
    print(sortJ)
    ans.append((sortI[-1] - sortI[0]) * (sortJ[-1] - sortJ[0]))
print("\n".join(map(str, ans)))