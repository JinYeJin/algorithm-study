def solution(prices):
	answer = []
	for i in range(len(prices)):
		start = i if i == len(prices)-1 else i+1
		for j in range(start, len(prices)):
			if prices[i] > prices[j] or j == len(prices)-1:
				answer.append(j-i)
				break
				
	return answer
	
'''
다른 사람의 코드


#스택 이용 반복문을 안돌아도 되는 상황을 걸러서 효율성을 높임
def solution(p):
    ans = [0] * len(p)
    stack = [0]
    for i in range(1, len(p)):
        if p[i] < p[stack[-1]]:
            for j in stack[::-1]:
                if p[i] < p[j]:
                    ans[j] = i-j
                    stack.remove(j)
                else:
                    break
        stack.append(i)
    for i in range(0, len(stack)-1):
        ans[stack[i]] = len(p) - stack[i] - 1
    return ans
    
#큐 이용
from collections import deque

def solution(prices):
    answer = []

    stock_prices = deque(prices)
    while len(stock_prices) >= 2:
        cur_price = stock_prices.popleft()

        lasted = 0
        for next_price in stock_prices:
            lasted += 1
            if next_price < cur_price:
                break

        answer.append(lasted)

    answer.append(0)
    return answer
    
    
#스택 이용
def solution(prices):
    stack = []
    answer = [0] * len(prices)
    for i in range(len(prices)):
        if stack != []:
            while stack != [] and stack[-1][1] > prices[i]:
                past, _ = stack.pop()
                answer[past] = i - past
        stack.append([i, prices[i]])
    for i, s in stack:
        answer[i] = len(prices) - 1 - i
    return answer


'''