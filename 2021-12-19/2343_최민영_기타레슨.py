n, m = map(int, input().split())
blueray = list(map(int, input().split()))
max_volume = sum(blueray)
min_volume = max(blueray)
volume = 0
while min_volume <= max_volume:
    cnt = 0
    temp_sum = 0
    mid_volume = (max_volume + min_volume) // 2
    for i in range(n):
        # 블루레이 디스크 한개의 용량이 mid보다 커질경우 필요한 blueray의 갯수를 늘려줌
        if temp_sum + blueray[i] > mid_volume:
            # 다시 여기부터 합해서 계산
            temp_sum = 0
            cnt += 1
        temp_sum += blueray[i]
    if temp_sum != 0:
        cnt += 1
    if cnt <= m:
        max_volume = mid_volume - 1
    else:
        min_volume = mid_volume+ 1
print(min_volume)
