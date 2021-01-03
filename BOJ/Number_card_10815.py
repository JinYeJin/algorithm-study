from sys import stdin

input()
N_cards = { int(x) for x in stdin.readline().split() }
M = int(input())
M_cards = [ int(x) for x in stdin.readline().split() ]

N_cards = sorted(list(N_cards))
N_len = len(N_cards)

for i in range(M):
	start = 0
	end = N_len-1
	target = M_cards[i]
	
	while start <= end:
		mid = (start + end)//2
		if target == N_cards[mid]:
			break
		elif target > N_cards[mid]:
			start = mid + 1
		else:
			end = mid - 1
	if target == N_cards[mid]:
		print("1", end=" ")
	else:
		print("0", end=" ")


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