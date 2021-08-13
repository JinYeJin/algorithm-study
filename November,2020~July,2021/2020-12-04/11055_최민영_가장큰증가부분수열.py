import sys
# dp 이용해서 계속 누적해 나가는 방식
def solution():
    input = sys.stdin.readline
    num = input()
    num_list = [i for i in list(map(int, input().split()))]
    # 누적 최대 sum이 저장 되는 중
    dp = [0 for _ in range(int(num))]
    # max = 0
    for i in range(int(num)):
        beforeSum = 0
        for j in range(i):
            # num_list[i] > num_list[j] 라는 것은 이전원소들의 모든 합을 더한것 가능
            if num_list[i] > num_list[j]:
                # 이전것까지 합한게 현재것보다 더 작다면 현재것을 대입 => 현재 j위치까지의 누적 합으로 바꾸기 위함
                if beforeSum < dp[j]:
                    beforeSum = dp[j]
        # 이전 위치까지의 누적합 + 현재 위치
        dp[i] = beforeSum + num_list[i]

        # dp들 중에서 최대 값을 찾기 => 시간 적음
        # if max < dp[i]:
        #     max = dp[i]
    return max(dp)

result = solution()
print(result)
