def solution(parti, comple):
	parti.sort()
	comple.sort()

	comp_ind = 0
	for pari_ind in range(len(parti)):
		
		while comp_ind < len(comple) and parti[pari_ind] != comple[comp_ind]:
			comp_ind += 1
		
		if comp_ind >= len(comple):
			return parti[pari_ind]
		
		comp_ind += 1
			
	return -1

parti = ['leo', 'kiki', 'eden']	 #["mislav", "stanko", "mislav", "ana"]
comple = ['eden', 'kiki']	 #["stanko", "ana", "mislav"]
print(solution(parti, comple))


'''
[leo, kiki, eden]	[eden, kiki]	leo
[marina, josipa, nikola, vinko, filipa]	[josipa, filipa, marina, nikola]	vinko
[mislav, stanko, mislav, ana]

'''