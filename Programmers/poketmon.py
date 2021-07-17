def solution(nums):
    nums_len = len(nums)
    return min(nums_len//2, len(set(nums)))

'''
최대한 많은 종류의 폰켓몬을 포함해서 N/2마리를 선택하려 합니다. 
N마리 폰켓몬의 종류 번호가 담긴 배열 nums가 매개변수로 주어질 때, 
N/2마리의 폰켓몬을 선택하는 방법 중, 
가장 많은 종류의 폰켓몬을 선택하는 방법


N/2, 중복없는 숫자 중 더 작은 것을 return
'''