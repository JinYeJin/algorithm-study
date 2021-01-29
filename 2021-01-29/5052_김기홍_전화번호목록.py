import sys
input = sys.stdin.readline

test_case = int(input())

while test_case:
    answer = "YES"
    n = int(input())
    phone_numbers = []
    for _ in range(n):
        phone_numbers.append(input().strip())
    phone_numbers.sort()
    for i in range(n - 1):
        if phone_numbers[i] == phone_numbers[i + 1][:len(phone_numbers[i])]:
            answer = "NO"
    print(answer)

    test_case -= 1
