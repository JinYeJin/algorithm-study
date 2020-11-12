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


''' 정답버전
def solution(words):
    answer = 0
    words = sorted(words)
    #print(words)
    
    for i in range(len(words)):
        #print('i: %d'%i)
        break_flag = 0
        break_a = False
        break_b = False
        for idx in range(len(words[i])):
           #print("idx: %d, a: %d b: %d"%(idx,break_a,break_b))
            
            if (i != len(words)-1):
                if (len(words[i+1]) > idx):
                    if words[i][idx] != words[i+1][idx]:
                        break_a = True
                        # 첫 번째 요소이면, 앞과 비교할 단어가 없으니 b까지 True
                        if i == 0:
                            break_a = True
                            break_b = True
                else:
                    break_a = True
                        
            if (i != 0):
                if (len(words[i-1]) > idx):
                    if words[i][idx] != words[i-1][idx]:
                        break_b = True
                        # 마지막 요소이면, 이후 비교할 단어가 없으니 a까지 True
                        if i == len(words)-1:
                            break_a = True
                            break_b = True
                else:
                    break_b = True
           	
            
            # 1. a, b  둘 다 조건을 만족하거나
            # 2. 끝가지 가야 다른 단어와 구분되거나
            # 3. "ab", "abc" 와 같은 경우
            if (break_a and break_b) or (len(words[i]) == idx+1):
                answer += idx+1
                #print(idx+1, answer, "\n")
                break
                
    return answer
    '''
