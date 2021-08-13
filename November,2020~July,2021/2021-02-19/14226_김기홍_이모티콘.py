from collections import deque

s = int(input())

q = deque()
q.append((1, 0))

visited = {}
visited[(1, 0)] = 0
answer = 0

while q:
    emo_cnt, clip_cnt = q.popleft()
    if emo_cnt == s:
        answer = visited[(emo_cnt, clip_cnt)]
        break
    if (emo_cnt, emo_cnt) not in visited.keys():
        visited[(emo_cnt, emo_cnt)] = visited[(emo_cnt, clip_cnt)] + 1
        q.append((emo_cnt, emo_cnt))
    if (emo_cnt + clip_cnt, clip_cnt) not in visited.keys():
        visited[(emo_cnt + clip_cnt, clip_cnt)] = visited[(emo_cnt, clip_cnt)] + 1
        q.append((emo_cnt + clip_cnt, clip_cnt))
    if (emo_cnt - 1, clip_cnt) not in visited.keys():
        visited[(emo_cnt - 1, clip_cnt)] = visited[(emo_cnt, clip_cnt)] + 1
        q.append((emo_cnt - 1, clip_cnt))
print(answer)