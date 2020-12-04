def solution():
    n, k = map(int, input().split())

    def bino(n, k):
        if k == 0 or n == k:
            return 1
        return bino(n - 1, k) + bino(n - 1, k - 1)

    result = bino(n,k) % 10007
    return result

result = solution()
print(result)
