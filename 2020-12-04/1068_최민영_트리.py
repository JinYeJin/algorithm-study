import sys
from collections import deque
# 0번부터 n-1번까지 주어짐
def solution():
    input = sys.stdin.readline
    node_number = int(input())
    node_list = list(map(int, input().split()))
    target = int(input())

    node_map = [[] for _ in range(node_number)]
    count, target_parent = 0, 0

    for index, value in enumerate(node_list):
        if value == -1:
            continue
        node_map[value].append(index)
        if index == target:
            target_parent = value

    # bfs
    visited = [ 0 for _ in range(node_number)]
    q_list = deque()
    q_list.append(target)
    visited[target] = -1
    while len(q_list) > 0:
        cur_node = q_list.popleft()
        visited[cur_node] = -1
        for node in node_map[cur_node]:
            if visited[node] == 0:
                q_list.append(node)

    for i in range(len(node_map)):
        if visited[i] == -1:
            node_map[i].append(-1)
        if len(node_map[i]) == 0:
            count += 1

    # target_parent의 노드가 target 뿐일때 고려
    if len(node_map[target_parent]) == 1 and node_map[target_parent][0] == target:
        count += 1

    return count
result = solution()
print(result)
