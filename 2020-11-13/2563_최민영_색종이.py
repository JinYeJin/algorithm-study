num = int(input())
color_paper = list()
for i in range(num):
    color_paper.append(tuple(map(int, input().split())))

# print(color_paper)

def solution(color_paper):
    arr = [[0 for i in range(100)] for j in range(100)]
    # print(arr)
    for color in color_paper:
        for i in range(color[0], color[0] + 10):
            for j in range(color[1], color[1] + 10):
                arr[i][j] += 1
    count = 0
    for a in arr:
        for i in a:
            if i != 0:
                count += 1
    print(count)
    
solution(color_paper)
