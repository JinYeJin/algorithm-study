def solution():
    a, b = input().split()
    diff_num = len(b) - len(a)
    before_a = b[0:diff_num] + a
    after_a = a + b[-diff_num:]

    before_a_count = 0
    after_a_count = 0
    mid_a_count = len(b)
    for i in range(len(b)):
        if before_a[i] != b[i]:
            before_a_count += 1
        if after_a[i] != b[i]:
            after_a_count += 1
    if a in b:
        mid_a_count = 0
    number = min(before_a_count, after_a_count)
    number = min(mid_a_count, number)
    return number
result = solution()
print(result)
