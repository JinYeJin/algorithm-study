# 중위 연산
# 값 변경 위해 클래스 이용
import sys
input = sys.stdin.readline
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

n = int(input())
# 각 레벨당 최대, 최소 저장하는 배열
l_max = [0] * (n + 1)
l_min = [n] * (n + 1)
trees = [Node(-1, -1, -1) for _ in range(n + 1)]
x = 1
root_index = 0
def inorder(root, level):
    global trees
    global x
    if trees[root].left != -1:
        inorder(trees[root].left, level + 1)
    l_max[level] = max(l_max[level], x)
    l_min[level] = min(l_min[level], x)
    x += 1
    if trees[root].right != -1:
        inorder(trees[root].right, level + 1)

for _ in range(n):
    root, l, r = map(int,input().split())
    trees[root].left = l
    trees[root].right = r
    if l != -1:
        trees[l].parent = root
    if r != -1:
        trees[r].parent = root

for i in range(1, n + 1):
    if trees[i].parent == -1:
        root_index = i
        break
inorder(root_index, 1)
val, f_level = 0, 0
for i in range(n + 1):
    gap = l_max[i] - l_min[i] + 1
    if gap > val:
        val = gap
        f_level = i
print(f_level, val)
