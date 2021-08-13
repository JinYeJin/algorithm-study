

import sys
input = sys.stdin.readline
n, k = map(int, input().split())
jewelArr = list()
bagArr = list()
jewelNumCount = list(range(1000000 + 1))
bagNumCount = list(range(1000000 + 1))
ans = 0

for i in range(n):
    m, v = map(int, input().split())
    jewelArr.append([m, v])

for i in range(k):
    bagArr.append(int(input()))


jewelArr.sort(key = lambda k : (k[0], k[1]))
bagArr.sort()

print(jewelArr)
print(bagArr)

for i in jewelArr:
    jewelNumCount[i[0]] += 1

for i in bagArr:
    bagNumCount[i] += 1

maxValue = 0
jewelIdx = -1
bagIdx = 0
while jewelIdx < len(jewelArr) and bagIdx < len(bagArr):
    jewelIdx += 1
    if jewelIdx >= len(jewelArr) or bagIdx >= len(bagArr):
        break
    if jewelNumCount[jewelArr[jewelIdx][0]] > 0 and jewelNumCount[jewelArr[jewelIdx][0]] == bagNumCount[bagArr[bagIdx]]:
        ans += jewelArr[jewelIdx][1]
        jewelNumCount[jewelArr[jewelIdx][0]] -= 1
        bagNumCount[bagArr[bagIdx]] -= 1
        bagIdx += 1
        continue
    if bagArr[bagIdx] < jewelArr[jewelIdx][0]:
        ans += maxValue
        maxValue = 0
        bagIdx += 1
        maxValue = max(maxValue, jewelArr[jewelIdx][1])
        continue
    maxValue = max(maxValue, jewelArr[jewelIdx][1])
    jewelNumCount[jewelArr[jewelIdx][0]] -= 1
    if len(jewelArr) - jewelIdx == len(bagArr):
        ans += jewelArr[jewelIdx][1]
        bagIdx += 1
print(ans)


    
