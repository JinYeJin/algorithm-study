import re

def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    print(new_id)
    
    filter2 = re.findall('[a-z0-9_\-\.]*', new_id)
    new_id = "".join(filter2)
    print(filter2)
    
    new_id = re.sub('\.\.+', '.', new_id)
    print(new_id)
    
    new_id = re.sub('^\.', '', new_id)
    new_id = re.sub('\.$', '', new_id)
    print(new_id)
    
    if len(new_id) == 0:
        new_id = 'a'
    
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[-1] == '.':
            new_id = new_id[:-1]
            
    if len(new_id) <= 2:
        while(len(new_id) < 3):
            new_id = new_id + new_id[-1]
            
    answer = new_id
    return answer
