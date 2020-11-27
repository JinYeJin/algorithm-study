def solution(clothes):
	ldict = {}
	mul = 1
	
	for item in clothes:
		if not ldict.get(item[-1]):
			ldict[item[-1]] = []
		ldict[item[-1]].append(item[0])
		
	for key in ldict.keys():
		mul *= len(ldict[key])+1

	return mul-1