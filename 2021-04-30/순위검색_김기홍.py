from itertools import combinations


def solution(info, query):
    answer = []
    d = {}
    for person in info:
        list_info = person.split(" ")
        rows = list_info[:-1]
        score = int(list_info[-1])
        for i in range(5):
            combis = list(combinations(range(4), i))
            for combi in combis:
                temp = rows.copy()
                for e in combi:
                    temp[e] = '-'
                temp = tuple(temp)
                if temp not in d:
                    d[temp] = [score]
                else:
                    d[temp].append(score)

    for value in d.values():
        value.sort()

    for qy in query:
        list_qy = [i for i in qy.split() if i != "and"]
        qy_rows = tuple(list_qy[:-1])
        qy_score = int(list_qy[-1])
        if qy_rows in d:
            score_list = d[qy_rows]
            left, right = 0, len(score_list) - 1
            while left <= right:
                mid = (left + right) // 2
                if score_list[mid] >= qy_score:
                    right = mid - 1
                else:
                    left = mid + 1
            answer.append(len(score_list) - left)
        else:
            answer.append(0)
    return answer
