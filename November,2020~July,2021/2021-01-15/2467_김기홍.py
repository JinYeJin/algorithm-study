n = int(input())

array = list(map(int, input().split()))

array.sort()

left = 0
right = n - 1
result = [abs(array[left] + array[right]), (array[left], array[right])]

while left < right:
    total = array[left] + array[right]
    if abs(total) < result[0]:
        result[0] = abs(total)
        result[1] = (array[left], array[right])
    if total < 0:
        left += 1
    elif total > 0:
        right -= 1
    else:
        break

print(result[1][0], result[1][1])
    