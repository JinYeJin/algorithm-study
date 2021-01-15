l, w, h = map(int, input().split())
total_size = l * w * h
n = int(input())
cube_list = list()
# 부피가 작다고 그게 정말 들어갈 수 있는지 확인 필요
for _ in range(n):
    # 큐브 종류, 갯수
    # 길이, 갯수
    i, number = map(int, input().split())
    # 부피와 갯수를 넣으면 될 듯
    cube_list.append((((2 ** i) ** 3), 2**i, number))
# 큐브에 개수의 최솟값
cube_list = sorted(cube_list, key=lambda x: x[0], reverse=True)
print(cube_list)
cnt = 0
for volume, r, num in cube_list:
    now_volume = volume * num
    if r > l or r > w or r > h:
        continue
    if total_size > now_volume:
        total_size -= now_volume
        cnt += num
    else:
        for j in range(num):
            total_size -= volume
            cnt += 1
            if total_size < 0:
                total_size += volume
                cnt -= 1
                break
    l, w, h = l-r, w-r, h-r
if total_size > 0:
    print(-1)
else:
    print(cnt)
