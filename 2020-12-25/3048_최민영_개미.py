# 처음 생각한 방식은 two-pointer 사용
# 이 방식의 경우 딱 2번씩만 교환되기 때문에 사용 불가
# 계속해서 교환되는 방식을 사용해야 함
def solution(len_ant1, len_ant2, ant1, ant2, mv):
    # 두개가 같은 문자열에 속하지 않을것을 만날때까지 계속 교체
    total_ant = ant1[::-1] + ant2

    for _ in range(mv):
        index = 0
        while index < len(total_ant) -1:
            # print("index", index)
            # 한번 바꾼 경우 그 index를 한번 더 추가시켜줘서 다음 번호를 건너뛰도록 만들어줌
            if total_ant[index] in ant1 and total_ant[index + 1] not in ant1:
                total_ant[index + 1], total_ant[index] = total_ant[index], total_ant[index + 1]
                index += 1
                # print("add index", index)
            index += 1
        # print("total_ant", total_ant)
    move_result = "".join(total_ant)
    return move_result

len_n1, len_n2 = map(int, input().split())
n1 = list(input())
n2 = list(input())
t = int(input())
result = solution(len_n1, len_n2, n1, n2, t)
print(result)
