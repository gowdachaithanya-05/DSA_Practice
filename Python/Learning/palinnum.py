"""brute force tecnique using string operations"""
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        o = str(x)
        r = str(x)[::-1]
        return o==r
             
        

""" optimal solution using math logic """
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        o = x
        r = 0
        while x>0:
            n = x%10
            r = (r*10) + n
            x = x//10

        return o==r
             
        
