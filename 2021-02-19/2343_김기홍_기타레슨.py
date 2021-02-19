n, m = map(int, input().split())

lessons = list(map(int, input().split()))

left = max(lessons)
right = sum(lessons)

answer = left

while left <= right:
    mid = (left + right) // 2
    
    record_cnt = 0
    lesson_sum = 0
    for i in range(n):
        if lesson_sum + lessons[i] > mid:
            record_cnt += 1
            lesson_sum = 0
        lesson_sum += lessons[i]
    else:
        if lesson_sum:
            record_cnt += 1

    if record_cnt > m:
        left = mid + 1
        answer = left
    else:
        right = mid - 1

print(answer)


