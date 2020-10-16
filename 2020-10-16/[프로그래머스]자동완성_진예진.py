def solution(words):
    answer = 0
    words = sorted(words)
    #print(words)
    
    for i in range(len(words)):
        break_flag = 0
        for idx in range(len(words[i])):
            if i != len(words)-1 and len(words[i+1]) > idx:
                if words[i][idx] != words[i+1][idx]:
                    break_flag += 1
                    if i == 0:
                        break_flag = 2
            if i != 0 and len(words[i-1]) > idx:
                if words[i][idx] != words[i-1][idx]:
                    break_flag += 1
                    # 마지막 요소이면
                    if i == len(words)-1:
                        break_flag = 2
                        
            if break_flag >= 2 or idx == len(words[i])-1:
                answer += idx+1
                #print(i, answer)
                break
    return answer
