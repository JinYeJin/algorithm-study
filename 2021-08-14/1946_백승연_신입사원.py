# import sys
#
# sys.stdin = open("1946.txt", "rt")
test_cases = int(input())

for _ in range(test_cases):
    n = int(input())
    arr = list()
    for i in range(n):
        score_a, score_b = map(int, input().split())
        arr.append((score_a, score_b))

    # 0번째는 큰 순, 1번째는 작은 순으로 정렬
    arr.sort(key=lambda x: (-x[0], x[1]))
    lis = []
    dp = [1] * n
    max_cnt = 0

    # 1번째 lis 에서 최대증가수열 찾기
    for x in arr:
        lis.append(x[1])

    for k in range(n):
        for j in range(k):
            if lis[j] <= lis[k]:
                dp[k] = max(dp[k], dp[j] + 1)
    max_cnt = max(dp)

    print(max_cnt)
