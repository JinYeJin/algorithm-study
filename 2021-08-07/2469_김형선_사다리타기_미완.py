k = int(input())
n = int(input())
result = input()
ladder = []

question_mark_index = 0
for i in range(n):
    ladder.append(input())
    if ladder[i][0] == '?':
        question_mark_index = i

# question_line = "*" * k
# for i in range(k):
#     for j in range(i, k):
#         if j == 0 or question_line[j - 1] == '*':
#             question_line[j] = '-'

while True:
    answer = ""
    if result == test_ladder(ladder):
        print(answer)
        break

def test_ladder(ladder):
    start = ""
    for i in range(k):
         start += 'A' + i
    result = '.' * k
    
    for start_c in range(k):
        c = start_c
        for r in range(n):
            if c != k-1 and ladder[r][c] == '-':
                c += 1
            if c != 0 and ladder[r][c-1] == '-':
                c += 1
    result[c] = start_c + 'A'
    return result
