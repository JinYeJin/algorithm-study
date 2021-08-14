N = int(input())

arr = [0]

def solve(index):
    if (len(arr) != index + 1 and arr[index] >= arr[index + 1]):
        arr[index] = 10
    if (arr[index] == 10):
        if (len(arr) == index + 1):
            arr.append(index)
        arr[index] = index
        arr[index + 1] += 1
        solve(index + 1)

for i in range(N):
    if (len(arr) > 10):
        break
    if (len(arr) == 1 or arr[1] > arr[0]):
        arr[0] += 1
    solve(0)

if len(arr) > 10:
    print(-1)
else:
    for num in reversed(arr):
        print(num, end="")
    print()
