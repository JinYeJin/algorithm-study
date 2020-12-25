import sys
acc, pc = 0,0
input = sys.stdin.readline
while True:
    memory = ["" for i in range(32)]
    acc, pc = 0, 0
    command_list = ['000', '001', '010', '011', '100', '101', '110', '111']

    def convertToBinary(val):
        change_val = val
        binary = ''
        while change_val > 0:
            div = change_val // 2
            mod = change_val % 2
            change_val = div
            binary += str(mod)
        return binary[::-1]

    for _ in range(32):
        memory[_] = input()
    while True:
        command = memory[pc][0:3]
        memory_loc = memory[pc][3:]
        pc = (pc + 1) % 32
        if command == command_list[0]:
            real_val = int(memory_loc, 2)
            change_acc = convertToBinary(acc)
            memory[real_val] = change_acc
        elif command == command_list[1]:
            real_loc = int(memory_loc, 2)
            acc = int(memory[real_loc], 2)
        elif command == command_list[2]:
            if acc == 0:
                pc = int(memory_loc, 2)
        elif command == command_list[3]:
            continue
        elif command == command_list[4]:
            acc -= 1
        elif command == command_list[5]:
            acc += 1
            if acc >= 256:
                acc = 0
        elif command == command_list[6]:
            real_val = int(memory_loc, 2)
            pc = real_val
        elif command == command_list[7]:
            print(convertToBinary(acc))
            # memory.clear()
            break
