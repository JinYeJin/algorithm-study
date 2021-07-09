import sys

sys.stdin = open("input/1700.txt")

N, K = map(int, input())

items = list(map(int, input()))
unpluged = 0
using = [False] * N
tab = []

for index, item in enumerate(items):
    if not using[item]:
        # 끝에서부터 비교
        remove_index = len(tab) + 1
        for tindex, t in enumerate(tab):
            try:
                found= items[index:].index(t)
            # 나중에 쓸 일이 없는 경우(무조건 뽑)
            except ValueError:
                remove_index = tindex
                break

            # t가 더 나중에 쓸 물건인 경우 found가 큼
            if remove_index < found:
                remove_index = tindex

        tab.remove(remove_index)
        unpluged += 1
