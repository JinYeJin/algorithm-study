import queue
max_y, max_x    = map(int, input().split())

world = [input() for _ in range(max_y)]

def bfs(x, y):
    visited = [[False for _ in range(max_x)] for _ in range(max_y)]
    q = queue.Queue()
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    
    visited[y][x] = True
    dist = 0
    q.put((dist, x, y))
    while (not q.empty()):
        dist, cur_x, cur_y = q.get()
        for i in range(4):
            new_x, new_y = cur_x + dx[i], cur_y + dy[i]
            if (new_x < max_x and new_y < max_y and not visited[new_y][new_x] and world[new_y][new_x] == 'L'):
                visited[new_y][new_x] = True
                q.put((dist + 1, new_x, new_y))
    return dist

max_dist = 0
for y in range(max_y):
    for x in range(max_x):
        if (world[y][x] == 'L'):
            max_dist = max(max_dist, bfs(x, y))
print(max_dist)
