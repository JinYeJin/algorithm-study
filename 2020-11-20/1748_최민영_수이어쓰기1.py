num = input()

len_num = len(num)
int_num = int(num)

def solution(int_num):
    global len_num
    result = 0
    for i in range(len_num):
        if i == 0:
            continue
        cal = i * 10 ** (i -1)
        result += cal
    result *= 9
    result += (int_num - (10**(len_num - 1))) * len_num + len_num
    return result

result = solution(int_num)
print(result)


