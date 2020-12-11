# * gap을 가지고 이진 탐색
# 1. 리스트 정렬
# 2. gap의 최소값과 최대값 구하기
# 3. 중간값 gap 구하기
# 4. 리스트의 처음 값을 추출하고 처음 값에서부터 반복적으로 gap을 더하면서 count의 갯수를 넘을 수 있는지 확인
#     4-1. count의 갯수보다 많이 존재할 수 있다면, 이진 탐색기법 사용하여 mid_gap 조절
#     4-2. count의 갯수보다 작다면, 마찬가지로 이진 탐색기법 사용하여 mid_gap 조절
# 5. 최소 gap이 최대 gap과 같을 경우에 break (이진 탐색 조건과 동일)

def solution():
    number, c = map(int, input().split())
    number_list = list()
    for _ in range(number):
        number_list.append(int(input()))
    number_list = sorted(number_list)
    max_gap = number_list[-1] - number_list[0]
    min_gap = 1
    gap = 0
    while min_gap <= max_gap:
        count = 1
        mid_gap = (max_gap + min_gap) // 2
        pos_value = number_list[0]
        for i in range(1, len(number_list)):
            if number_list[i] >= pos_value + mid_gap:
                count += 1
                pos_value = number_list[i]
        if count >= c:
            min_gap = mid_gap + 1
            gap = mid_gap
        else:
            max_gap = mid_gap - 1
    return gap
result = solution()
print(result)
