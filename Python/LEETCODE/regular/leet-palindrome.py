
""" Brute Force approach 
step 1: create a list
step 2: append this alphanumeric char to list
step 3: convert list to string (str1)
step 4: reverse the string(str2)
step 5: retuen str1 == str2

time complexity : O(1)
"""
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        list = []
        for c in s:
            if c.isalnum():
                list.append(c.lower())

        str1 = ''.join(list)
        #str[start:end:step]
        str2 = str1[::-1]

        return str1 == str2
         
                       

""" this is solution includes two pointer solution
    step 1: eleminate alphanumeric by skipping them 
    step 2: compare left and right, if true false return false
    step 3: return true
    
    time complexity : O(n)
"""
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left=0
        right = len(s) - 1
        while left < right:
            if not s[left].isalnum():
                left+=1
            elif not s[right].isalnum():
                right-=1
            elif s[left].lower() != s[right].lower():
                return False
            else:
                left+=1
                right-=1

        return True                    


""" regular expression 
step 1: eliminate non alphanumeric elemets add to filtered
step 2: compare filtered string with reversed string
O(1)
"""
import re

class Solution(object):
    def isPalindrome(self, s):
        filtered = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        return filtered == filtered[::-1]
