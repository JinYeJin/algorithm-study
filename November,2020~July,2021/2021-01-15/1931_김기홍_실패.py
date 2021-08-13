n = int(input())

array = []

for _ in range(n):
    # 시작 시간, 끝나는 시간
    a, b = map(int, input().split())
    array.append((a, b, abs(a - b)))

array.sort(key = lambda x : x[2])

answer = 1
start = array[0][0]
end = array[0][1]

for i in range(1, len(array)):
    tmp_s, tmp_e, tmp_c = array[i]

    if tmp_s >= end:
        end = tmp_e
        answer += 1

print(answer)
