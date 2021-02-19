n, m = map(int, input().split())
numbers = list(map(int, input().split()))
end, sum, cnt = 0, 0, 0
for i in range(n):
    while sum < m and end < n:
        sum += numbers[end]
        end += 1
    if sum == m:
        cnt += 1
    sum -= numbers[i]
print(cnt)
