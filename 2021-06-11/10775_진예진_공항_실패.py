import sys
sys.stdin = open("input/10775.txt")

def check(index):
    global airplane
    if index < airplane:
        if avail[index] == False:
            gate[index] = check(gate[index])
            return gate[index]
        else:
            avail[index] = False
            gate[index] += 1
            return gate[index]
    else:
        return -1


G = int(input())
P = int(input())

avail = [True] * (G+1)
gate = [i for i in range(G)]

docked = 0

for p in range(P):
    airplane = int(input())
    result = check(0)
    print(gate)
    print(avail)
    if result != -1:
        docked += 1
    else:
        print(docked)
        exit(0)
