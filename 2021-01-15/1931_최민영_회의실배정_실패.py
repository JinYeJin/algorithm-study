n = int(input())
hall_list = list()
min_s, max_e = 0, 0
for _ in range(n):
    s, e = map(int, input().split())
    if e > max_e:
        max_e = e
    hall_list.append((s, e, e-s))
# print(hall_list)
hall_list = sorted(hall_list, key=lambda x: x[0])
# print(hall_list)
count = 1
i = 0
while i < n-1:
    now_s, now_e, diff = hall_list[i]
    j = i + 1
    # 일단 그 간격을 줄여가는 형태로 진행
    while j < n:
        next_s, next_e, next_diff = hall_list[j]
        if now_e > next_e:
            now_s, now_e, diff = hall_list[j]
            i = j
        else:
            j += 1
    k = i + 1
    # while k < n:
    #     if now_e

    count = max(cnt, count)

print(count)
