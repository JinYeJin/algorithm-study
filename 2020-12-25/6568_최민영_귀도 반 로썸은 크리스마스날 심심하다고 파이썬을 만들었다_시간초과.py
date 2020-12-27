while True:
    memory = []
    acc, pc = 0, 0

    for _ in range(32):
        try:
            memory.append(input())
        # 입력 에러시 종료
        except:
            exit(0)
    while True:
        pos = memory[pc]
        command = pos[0:3]
        memory_loc = int(pos[3:], 2)
        pc = (pc + 1) % 32
        if command == "000":
            # 2진수로 변경시켜주는 형식
            # 자체 함수는 시간을 너무 많이 먹어서 런타임 오류 발생
            memory[memory_loc] = format(acc, '08b')
        elif command == "001":
            acc = int(memory[memory_loc], 2)
        elif command == "010":
            if acc == 0:
                pc = memory_loc
        elif command == "011":
            continue
        elif command == "100":
            # -1 하고 조건문 쓰면 시간초과 발생해서 비트 연산 사용
            acc += 255
            acc %= 256
        elif command == "101":
            # 시간 초과 막기 위한 비트 연산
            acc += 1
            acc %= 256
        elif command == "110":
            pc = memory_loc
        else:
            # 2진수로 변환해서 출력
            print(format(acc, '08b'))
            break
