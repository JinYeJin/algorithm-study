def solution(phone_book):
	phone_book.sort()
	for first_index in range(len(phone_book)):
		for second_index in range(first_index+1, len(phone_book)):
			if phone_book[second_index].find(phone_book[first_index]) ==0:
				return False

	return True


phone_book = ["12","123","1235","567","88"]#["123","456","789"] #["119", "1197674223", "11195524421"]
print(solution(phone_book))
'''
[119, 97674223, 1195524421]	false
[123,456,789]	true
["12","123","1235","567","88"]	false

======= 다른 사람 코드
# 정렬 없이 탐색
def solution(phone_book):
	for i in range(len(phone_book)):
		pivot = phone_book[i]
		for j in range(i+1, len(phone_book)):
			strlen = min(len(pivot), len(phone_book[j])) 
			if pivot[:strlen] == phone_book[j][:strlen]: 
				return False 
	return True
    
#해시
def solution(phone_book):
    answer = True
    hash_map = {}
    for phone_number in phone_book:
        hash_map[phone_number] = 1
    for phone_number in phone_book:
        temp = ""
        for number in phone_number:
            temp += number
            if temp in hash_map and temp != phone_number:
                answer = False
    return answer
    
#sorted(key=len), combinations
문자열 자체를 가지고 정렬이 아니라 문자열의 길이를 기준으로 정렬해서 더 빠른 듯 하다.

from itertools import combinations as c
def solution(phoneBook):
    answer = True
    sortedPB = sorted(phoneBook, key= len)
    for (a,b) in c( sortedPB,2):
        if a == b[:len(a)]:
            answer = False
    return answer

'''