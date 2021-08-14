import sys
import re

sys.stdin = open("1543.txt", "rt")

find_str = input()
target_str = input()

indexs = [x.start() for x in re.finditer(target_str, find_str)]

print(len(indexs))
