from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for num in course:
        d = {}
        candidates = []
        for order in orders:
            for combi in combinations(order, num):
                res = "".join(sorted(combi))
                if res not in candidates:
                    candidates.append(res)
                else:
                    if res not in d:
                        d[res] = 2
                    else:
                        d[res] += 1
        d_list = sorted(d.items(), key = lambda x : x[1])
        if d_list:
            print(d_list)
            result, cnt = d_list.pop()
            answer.append(result)
            while True:
                if d_list:
                    if d_list[-1][1] == cnt:
                        r, c = d_list.pop()
                        answer.append(r)
                    else:
                        break
                else:
                    break
    answer.sort()
    return answer