import sys
sys.stdin = open("input/1089.txt")


zero = ["###", "#.#", "#.#", "#.#", "###"]
one = ["..#", "..#", "..#", "..#", "..#"]
two = ["###", "..#", "###", "#..", "###"]
three = ["###", "..#", "###", "..#", "###"]
four = ["#.#", "#.#", "###", "..#", "..#"]
five = ["###", "#..", "###", "..#", "###"]
six = ["###", "#..", "###", "#.#", "###"]
seven = ["###", "..#", "..#", "..#", "..#"]
eight = ["###", "#.#", "###", "#.#", "###"]
nine = ["###", "#.#", "###", "..#", "###"]

windows = [zero, one, two, three, four, five, six, seven, eight, nine]


def get_cadidate(number):
    candi = []
    for index, window in enumerate(windows):
        is_candi = True
        for r in range(5):
            for c in range(3):
                # 이 경우에 candidate에서 제외
                if window[r][c] == '.' and number[r][c] =="#":
                    is_candi = False
                if not is_candi:
                    break
            if not is_candi:
                break
        if is_candi: candi.append(index)
    return candi


def get_average(candi):
    # for i in candi
    pass


N = int(input())

input_numbers = []

for i in range(5):
    input_numbers.append(input())
print(input_numbers)

numbers = []
candidate = []

for c in range(0, 3*N + (N-1), 4):
    temp = []
    print("c", c, "r", c)
    for r in range(5):
        temp.append(input_numbers[r][c:c+3])
    print("temp", temp)
    numbers.append((temp))
    candidate.append(get_cadidate(temp))

print(candidate)
