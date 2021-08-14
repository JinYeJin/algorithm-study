from sys import stdin
input = stdin.readline
T = int(input())

for _ in range(T):
    N = int(input())
    table = [0] * (N)
    for _ in range(N):
        doc_rank, interview_rank = map(int, input().split())
        table[doc_rank - 1] = interview_rank
    count = 1
    min_rank = table[0]
    for i in range(1, N):
        if (table[i] <= min_rank):
            count += 1
            min_rank = table[i]
    print(count)
