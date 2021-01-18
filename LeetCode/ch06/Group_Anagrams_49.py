class Solution:	
	from collections import defaultdict

	def groupAnagrams(self, strs: List[str]) -> List[List[str]]:		
		answer_dict = defaultdict(list)

		for word in strs:
			sorted_word = ''.join(sorted(word))
			answer_dict[sorted_word].append(word)

		print(f"{answer_dict}")
		result = []
		for val in answer_dict.values():
			result.append(val)

		return result

'''
순서 상관없다는 것에 
Counter를 쓰면 되지않을까 했지만 해시 키로 쓸 수 는 없었다.
그렇다고 혹시 유니크하지 않을까해서 
각 스펠링별로 unicode를 써서 더하거나 곱해보았지만 
아나그램이 아니어도 중복되는 경우가 발생했다
다시 문제를 읽고 
순서에 상관없으니  소팅을해도 되겠다 생각들어  풀리긴하였으나
시간 소요가 컸다 
'''