class Solution:
    def isPalindrome(self, s: str) -> bool: 
       
        s = s.lower().replace(" ", "")
        bad_chars = [';', ':', '!', "*", ",", '.','@','#','$','%','^','&','(', ')', '_' , '=' , '+', '#', '[' , ']', '{', '}' , "'", '"', '-', '?','`']
        for i in bad_chars :
            s = s.replace(i, '')

        str_len = len(s)
        if str_len == 0:
            return True

        mid = str_len//2
        for i in range(mid):
            if s[i] != s[-1-i]:          
                return False
        
        return True
        
 '''
 # 다른이의 코드
 import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # reverse 사용하면 되지않나?
        s = re.sub('[-=+,#/\?:^$.@*_\{}"※~;&%ㆍ!』\\‘|\(\)\[\]\<\>`\'…》]', '', s) 
        s = s.replace(" ", "")
        s = s.lower()
        reverse = ''.join(reversed(s))
        # print(''.join(reversed(s)))
        # reverse = re.sub('[-=+,#/\?:^$.@*\"※~&%ㆍ!』\\‘|\(\)\[\]\<\>`\'…》]', '', reverse)
        
        # print(s)
        # print(reverse)
        
        
        if s == reverse:
        
        
class Solution(object):
    def isPalindrome(self, s):
        s = s.lower() 
        text = re.sub('[^a-zA-Z0-9]','',s)
        return text == text[::-1]
        """
        :type s: str
        :rtype: bool
        
        
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s =[ch.lower() for ch in s if ch.isalnum() ]
        return tuple(s) == tuple(reversed(s))
        
  '''