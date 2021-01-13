class Solution:
	from collections import Counter, defaultdict, OrderedDict
	def groupAnagrams(self, strs: List[str]) -> List[List[str]]:			
		answer_dict = defaultdict(list)		

		for word in strs:
			ascii_sum = 1
			for ch in word:
				ascii_sum *= ord(ch)
			key = '_'.join([str(ascii_sum), str(len(word))])
			answer_dict[key].append(word)

		result = []
		for val in answer_dict.values():
			result.append(val)

		return result
