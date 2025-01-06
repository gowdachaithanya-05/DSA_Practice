"""Problem Statement: Given an integer N, return true it is an Armstrong number otherwise return false.

An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits."""

# Brute force method 
"""step 1: convert to string 
   step 2: add pow of length for all the digit
   step 3: return n == sum """
def arm(n):
    s = str(n)
    l = len(s)
    sum = 0
    for i in s:
        sum = sum + pow(int(i),l)

    return n==sum

a = arm(371)
print(a)

"""Mathematical approach without converting to str
same logic of reverse number"""
def arm(n):
    sum = 0
    temp = n
    while temp > 0:
        digit = temp % 10
        sum = sum + pow(digit, len(str(n)))
        temp = temp // 10
    return n == sum 

print(arm(371))