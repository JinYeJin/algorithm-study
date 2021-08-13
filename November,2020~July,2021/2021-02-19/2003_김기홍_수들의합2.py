n, m = map(int, input().split())

arr = list(map(int, input().split()))

result = 0

for i in range(n):
    check_sum = arr[i]
    for j in range(i + 1, n):
        if check_sum < m:
            check_sum += arr[j]
        elif check_sum > m:
            check_sum = 0
            break
        else:
            check_sum = 0
            result += 1
            break
    if check_sum == m:
        result += 1
print(result)
