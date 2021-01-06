from sys import stdin

def meeting_count(N, time_table):
	meeting_cnt = 0
	if N == 0:
		return meeting_cnt
	else:
		cur_meet_start = time_table[0][0]
		cur_meet_end = time_table[0][1]
		meeting_cnt += 1

	for i in range(1,N):
		
		next_meet_start = time_table[i][0]
		next_meet_end = time_table[i][1]
        #다음 미팅이 현재 미팅 종료시간 안에 시작하는 확인
		if next_meet_start < cur_meet_end:
			
			#다음 미팅이 현재 미팅보다 먼저 끝나면 현재 미팅을 바꿈
			if time_table[i][1] < cur_meet_end:
				cur_meet_start = time_table[i][0]
				cur_meet_end = time_table[i][1]
				
		#다음 미팅 시작시간이 현재 미팅 종료시간보다 늦은지 확인 (현재 미팅이 이미 끝났는지)	
		else:
			cur_meet_start = time_table[i][0]
			cur_meet_end = time_table[i][1]
			meeting_cnt += 1

	return meeting_cnt

N = int(input())
time_table = [ tuple(map(int, stdin.readline().split())) for _ in range(N) ]
time_table.sort(key=lambda x : x[0])
print(meeting_count(N, time_table))

'''
import sys
input = sys.stdin.readline
n = int(input())
x = []
for i in range(n):
    u, v = map(int, input().split())
    x.append((v, u))
x.sort()

y = 0
ans = 0
for i in x:
    if i[1] < y:
        continue
    ans += 1
    y = i[0]
print(ans)
'''