n, k = map(int, input().split())

belt = list(map(int, input().split()))
robot = [False] * n
step = 0


def robot_rotate():
    front = belt.pop()
    belt.insert(0, front)
    front = robot.pop()
    robot.insert(0, front)
    if robot[n - 1]:
        robot[n - 1] = False

    for i in range(n - 3, -1, -1):
        # 로봇이 있는 경우
        if robot[i]:
            # 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도 1 이상
            if robot[i + 1] == False and belt[i + 1] > 0:
                belt[i + 1] -= 1
                robot[i], robot[i - 1] = robot[i - 1], robot[i]

    if belt[0] > 0:
        robot[0] = True
        belt[0] -= 1

    if belt.count(0) >= k:
        return False

    return True



while True:
    if belt[0] > 0:
        robot[0] = True
        belt[0] -= 1
    step += 1
    if not robot_rotate():
        break
print(step)
