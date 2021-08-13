# 1. 팩토리얼 값 구함
# 2. 구한 값의 길이 구함
# 3. 구한 값을 10으로 반복적으로 나눔
#     3-1. 나눈 나머지가 0이 아닐 경우 break
#     3-2. 나눈 나머지가 0일 경우 count 증가
n = int(input())
def solution(n):
    def factorial(n):
        if n == 0:
            return 1
        return n * factorial(n - 1)
    result = factorial(n)
    len_result = len(str(result))
    count = 0
    while result > 0:
        mod = result % 10
        result = result // 10
        if mod != 0:
            break
        elif mod == 0:
            count += 1
    if count > len_result:
        return 0
    return count
result = solution(n)
print(result)
