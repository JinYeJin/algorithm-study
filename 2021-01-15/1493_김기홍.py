import sys
input = sys.stdin.readline

l, w, h = map(int, input().split())
n = int(input())

array = [0] * 21

for _ in range(n):
    a, b = map(int, input().split())
    array[a] += b

volume = 0
result = 0

for i in range(19, -1, -1):
    # 크기가 한 단계 줄어들면 개수가 2^3만큼 늘어나게 된다.
    volume <<= 3
    tmp = min(array[i], (l >> i) * (w >> i) * (h >> i) - volume)
    volume += tmp
    result += tmp

if volume == l * w * h:
    print(result)
else:
    print(-1)

## 의문1 -> array[i]가 0인 부분을 continue하면 문제가 되는 경우?
## 의문2 -> 그리드의 정당성이 입증 되는지?