import heapq
child_number = int(input())
present_list = list()
for _ in range(child_number):
    data = list(map(int, input().split()))
    if len(data) == 1 and data[0] == 0:
        if len(present_list) == 0:
            print(-1)
        else:
            print(-heapq.heappop(present_list))
    else:
        for p in data[1:]:
            heapq.heappush(present_list, -p)
