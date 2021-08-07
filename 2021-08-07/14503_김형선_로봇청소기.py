max_r, max_c  = map(int, input().split())

r, c, d = map(int, input().split())
wall = [list(map(int, input().split())) for _ in range(max_r)]
cleaned = [[False for _ in range(max_c)] for _ in range(max_r)]

class Robot:
    def __init__(self, r, c, d):
        self.r = r
        self.c = c
        self.d = d

    def rotate(self):
        self.d = (self.d - 1) % 4
    
    def move(self):
        if self.d == 0:
            self.r -= 1
        if self.d == 1:
            self.c += 1
        if self.d == 2:
            self.r += 1
        if self.d == 3:
            self.c -= 1

    def move_back(self):
        self.r, self.c = self.back()

    def front(self):
        if self.d == 0:
            return (self.r - 1, self.c)
        if self.d == 1:
            return (self.r, self.c + 1)
        if self.d == 2:
            return (self.r + 1, self.c)
        if self.d == 3:
            return (self.r, self.c - 1)

    def back(self):
        if self.d == 0:
            return (self.r + 1, self.c)
        if self.d == 1:
            return (self.r, self.c - 1)
        if self.d == 2:
            return (self.r - 1, self.c)
        if self.d == 3:
            return (self.r, self.c + 1)

robot = Robot(r, c, d)
clean_count = 0
while not wall[robot.r][robot.c]:
    if cleaned[robot.r][robot.c] == False:
        cleaned[robot.r][robot.c] = True
        clean_count += 1

    rotate_count = 0
    while rotate_count < 4:
        robot.rotate()
        rotate_count += 1
        front = robot.front()
        if not cleaned[front[0]][front[1]] and not wall[front[0]][front[1]]:
            robot.move()
            break
        if rotate_count == 4:
            robot.move_back()

print(clean_count)
