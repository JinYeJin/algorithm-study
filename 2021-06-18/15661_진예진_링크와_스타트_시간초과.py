import sys
sys.stdin = open("input/15661.txt")


def get_diff():
    f_score = 0
    t_score = 0
    #print(f_team)
    #print(t_team)

    for i in range(len(f_team)):
        for j in range(len(f_team)):
            f_score += score[f_team[i]][f_team[j]]

    for i in range(len(t_team)):
        for j in range(len(t_team)):
            t_score += score[t_team[i]][t_team[j]]

    #print(f_score)
    #print(t_score)
    return abs(f_score - t_score)


def select(index, selected):
    #print("select~~")
    global answer
    if index >= N:
        return
    if selected >= 1:
        for i in range(N):
            if person[i]:
                t_team.append(i)
            else:
                f_team.append(i)
        answer = min(answer, get_diff())
        t_team.clear()
        f_team.clear()

    # 선택 안함
    select(index+1, selected)

    # 선택함
    person[index] = True
    select(index+1, selected+1)
    person[index] = False


### input

N = int(input())
score = []
person = [False for _ in range(N)]
f_team = []
t_team = []
answer = 987654321


for n in range(N):
    temp = input().split()
    score.append(list(map(int, temp)))

#print(score)

select(0, 0)
print(answer)
