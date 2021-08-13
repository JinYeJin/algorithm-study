h, w, x, y = map(int, input().split())

B = []
A = [[0] * w for _ in range(h)]

for _ in range(h + x):
    B.append(list(map(int, input().split())))

for i in range(h + x):
    for j in range(w + y):
        if i < x and j < w:
            A[i][j] = B[i][j]
        elif  i < h and j < y:
            A[i][j] = B[i][j]
        elif i >= x and j >= y and i < h and j < w:
            A[i][j] = B[i][j] - A[i - x][j - y]

for row in A:
    for e in row:
        print(e, end=" ")
    print()