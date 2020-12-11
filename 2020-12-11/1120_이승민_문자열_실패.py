# 문자열

st1, st2 = input().split()
# l = len(st2) - len(st1)
ans1 = 0
ans2 = [0] * len(st1)
for i in range(len(st1)):
    if st1[i : i + 1] != st2[i : i + 1]:
        ans1 += 1
for j in range(len(st2) - 1):
    for i in range(len(st1)):
        if st1[i : i + 1] != st2[i + 1 : i + 2]:
            ans2[j] += 1
if ans1 < min(ans2):
    print(ans1)
else:
    print(min(ans2))
