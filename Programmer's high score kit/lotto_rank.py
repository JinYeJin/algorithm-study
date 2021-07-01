def solution(lottos, win_nums):
    match_num = 0
    magic_num = 0
    # match_num: rank
    ranks = { 6: 1, 5: 2, 4: 3, 3: 4, 2: 5, 1: 6, 0: 6}
    
    for lot_num in lottos:
        if lot_num in win_nums:
            match_num += 1
        if lot_num == 0:
            magic_num += 1
    return [ranks[match_num + magic_num], ranks[match_num]]