max_y, max_x  = map(int, input().split())
pinfold = [input() for _ in range(max_y)]
visited = [[False for _ in range(max_x)] for _ in range(max_y)]

def check_wolf_or_sheep(x, y, wolf_count, sheep_count):
    if (pinfold[y][x] == 'v'):
        wolf_count += 1
    elif pinfold[y][x] == 'o':
        sheep_count += 1
    return (wolf_count, sheep_count)

queue = list()
total_wolf_count = 0
total_sheep_count = 0
for y in range(max_y):
    for x in range(max_x):
        if visited[y][x] == True or pinfold[y][x] == '#':
            continue
        wolf_count, sheep_count = check_wolf_or_sheep(x, y, 0, 0)
        queue.append((x, y))
        visited[y][x] = True
        while len(queue) != 0:  
            cursor = queue.pop(0)
            if cursor[0] > 0 and not visited[cursor[1]][cursor[0] - 1] and pinfold[cursor[1]][cursor[0] - 1] != '#':
                wolf_count, sheep_count = check_wolf_or_sheep(cursor[0] - 1, cursor[1], wolf_count, sheep_count)
                visited[cursor[1]][cursor[0] - 1] = True
                queue.append((cursor[0] - 1, cursor[1]))
            if cursor[1] > 0 and not visited[cursor[1] - 1][cursor[0]] and pinfold[cursor[1] - 1][cursor[0]] != '#':
                wolf_count, sheep_count = check_wolf_or_sheep(cursor[0], cursor[1] - 1, wolf_count, sheep_count)
                visited[cursor[1] - 1][cursor[0]] = True
                queue.append((cursor[0], cursor[1] - 1))
            if cursor[0] < max_x - 1 and not visited[cursor[1]][cursor[0] + 1] and pinfold[cursor[1]][cursor[0] + 1] != '#':
                wolf_count, sheep_count = check_wolf_or_sheep(cursor[0] + 1, cursor[1], wolf_count, sheep_count)
                visited[cursor[1]][cursor[0] + 1] = True
                queue.append((cursor[0] + 1, cursor[1]))
            if cursor[1] < max_y - 1 and not visited[cursor[1] + 1][cursor[0]] and pinfold[cursor[1] + 1][cursor[0]] != '#':
                wolf_count, sheep_count = check_wolf_or_sheep(cursor[0], cursor[1] + 1, wolf_count, sheep_count)
                visited[cursor[1] + 1][cursor[0]] = True
                queue.append((cursor[0], cursor[1] + 1))
        if wolf_count >= sheep_count:
            total_wolf_count += wolf_count
        else:
            total_sheep_count += sheep_count

print(total_sheep_count, total_wolf_count)
