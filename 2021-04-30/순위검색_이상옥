from bisect import bisect_left

DP=dict()

def get_query(query,info):
    if query not in DP.keys():
        for i in range(4):
            if query[i]!='-':
                info=[j for j in info if j[i+1]==query[i]]
        DP[query]=info
    return DP[query]

def solution(info, query):
    info = [i.split(' ') for i in info]
    for i in range(len(info)):
        info[i]=[int(info[i][-1])]+info[i][:-1]
    info.sort()
    query = [i.split(' and ') for i in query]
    for q in query:
        q.extend(q[-1].split(' '))
        del q[-3]
    result=[]
    for q in query:
        info_q = get_query(tuple(q[:4]),info)
        result.append(len(info_q)-bisect_left(info_q,[int(q[4])]))
    return result
