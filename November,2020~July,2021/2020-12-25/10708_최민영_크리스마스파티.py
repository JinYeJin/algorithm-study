import sys
input = sys.stdin.readline

def solution(friend_number, game_number, target_list):
    game_data = list()
    result = [0 for _ in range(friend_number)]
    for _ in range(game_number):
        data = list(map(int, input().split()))
        game_data.append(data)
    for index, target in enumerate(target_list):
        for num in range(friend_number):
            if game_data[index][num] == target:
                result[num] += 1
            else:
                result[target-1] += 1
    return result

n = int(input())
m = int(input())
x = list(map(int, input().split()))
result = solution(n, m, x)
for data in result:
    print(data)
