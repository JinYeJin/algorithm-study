N = int(input())

fatorial_value = 1
for x in range(N,0,-1):
	fatorial_value *=  x

fatorial_value = list(str(fatorial_value))
fatorial_len = len(fatorial_value)
cnt = 0
for i in range(fatorial_len-1,-1,-1):
	if fatorial_value[i] == '0':
		cnt += 1
	else:
		break

print(cnt)


# end_time = time.time()
# runtime = end_time - start_time
# print(f"{runtime=}")
# print(f"{result=}")

'''
#다른이의 코드

x=input
x()
a=set(x().split())
x()
print(' '.join(['1' if j in a else '0' for j in x().split()]))


"""BOJ Q10815 - 숫자 카드 (https://www.acmicpc.net/problem/10815)
"""

n = int(input())
nums = set(input().split())
m = int(input())
print(' '.join('1' if x in nums else '0' for x in input().split()))


import sys
if __name__=='__main__':
    input()
    x = set(input().split())
    input()
    sys.stdout.write(' '.join(['1' if i in x else '0' for i in input().split()]))



'''