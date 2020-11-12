import re
import os

# print(os.getcwd())
# f = open("S2\\20\\input\\2671.txt", "r")
# file_input = f.read()
# input_sound = file_input
# f.close()


input_sound = input()

pattern = re.compile('(100+1+|01)+')
ret = pattern.fullmatch(input_sound)
# print(ret.group())

if ret == None:
    print("NOISE")
elif len(ret.group()) == len(input_sound):
    print("SUBMARINE")
else:
    print("NOISE")
