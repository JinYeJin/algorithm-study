def solution():
    num = input()
    num_count = [0 for _ in range(10)]

    for i in num:
        num_count[int(i)] += 1

    max_val = 0
    for index, val in enumerate(num_count):
        if index == 6 or index == 9:
            continue
        if max_val < val:
            max_val = val

    six_or_nine = (num_count[6] + num_count[9]) // 2
    if (num_count[6] + num_count[9]) % 2 != 0:
        six_or_nine += 1

    max_val = max(six_or_nine, max_val)
    return max_val

result = solution()
print(result)
