#optimal solution because no string opearators used, direct conversion is involved

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        res=0
        if x < 0:
            sign = -1
            x = abs(x)
        else:
            sign = 1
        while not x == 0: 

            digit = x%10
            res = (res*10)+digit
            x = x//10

        res = res * sign 
        if res < -2**31 or res > 2**31 - 1:
            return 0   
        return res

#brute force approach which includes string operations that is reverse string 
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        reversed_str = str(x)[::-1]
        
        res = sign * int(reversed_str)
        
        if res < -2**31 or res > 2**31 - 1:
            return 0
        
        return res
