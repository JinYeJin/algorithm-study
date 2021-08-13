import sys
input = sys.stdin.readline
n = int(input())
liquid_list = list(map(int, input().split()))
st, end = 0, n - 1
tmp1, tmp2 = st, end
# 처음에 close 값을 abs값으로 설정하지 않았을때 에러 발생
close = abs(liquid_list[st] + liquid_list[end])
while st < end:
    val = liquid_list[st] + liquid_list[end]
    if val == 0:
        tmp1, tmp2 = st, end
        break
    if abs(val) < abs(close):
        close = abs(val)
        tmp1, tmp2 = st, end
    if val < 0:
        st += 1
    if val > 0:
        end -= 1

print(liquid_list[tmp1], liquid_list[tmp2])
