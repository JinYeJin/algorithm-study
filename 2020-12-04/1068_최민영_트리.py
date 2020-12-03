import sys
from collections import deque

def solution():
    input = sys.stdin.readline
    node_number = int(input())
    node_list = list(map(int, input().split()))
    target = int(input())

    root = 0
    count = 0
    if len(node_list) > 1:
        root = node_list[1]
    target_parent = -1

    node_map = [[] for _ in range(node_number + root)]
    for index, value in enumerate(node_list):
        if value == -1:
            continue
        node_map[value].append(index + root)
        if index + root == target:
            target_parent = value

    visited = [ 0 for _ in range(node_number + root)]
    q_list = deque()
    q_list.append(target)
    visited[target] = -1
    while len(q_list) > 0:
        cur_node = q_list.popleft()
        visited[cur_node] = -1
        for node in node_map[cur_node]:
            if visited[node] == 0:
                q_list.append(node)

    result = list()

    for i in range(root, len(node_map)):
        if visited[i] == -1:
            node_map[i].append(-1)
        if len(node_map[i]) == 0:
            count += 1
            result.append(i)


    if len(node_map[target_parent]) == 1 and node_map[target_parent][0] == target:
        print("target_parent", node_map[target_parent])
        count += 1
        result.append(target_parent)
    print(visited)
    print(node_map)
    print(result)
    return count
result = solution()
print(result)
