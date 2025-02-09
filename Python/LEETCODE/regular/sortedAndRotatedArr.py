# 1752. Check if Array Is Sorted and Rotated
# Solved
# Easy
# Topics
# Companies
# Hint
# Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

# There may be duplicates in the original array.

# Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

# Example 1:

# Input: nums = [3,4,5,1,2]
# Output: true
# Explanation: [1,2,3,4,5] is the original sorted array.
# You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
# Example 2:

# Input: nums = [2,1,3,4]
# Output: false
# Explanation: There is no sorted array once rotated that can make nums.
# Example 3:

# Input: nums = [1,2,3]
# Output: true
# Explanation: [1,2,3] is the original sorted array.
# You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 


# Brute force method

# pop the first element and append it to the end of the array 
# check if the array is sorted
# return true if sorted else repeat

class Solution:
    def check(self, nums):
        def is_sorted(arr):
            for i in range(len(arr) - 1):
                if arr[i] > arr[i + 1]: 
                    return False
            return True 
        
        for i in range(len(nums)):
            nums.append(nums.pop(0))

            if is_sorted(nums):
                return True
        
        return False  


# Optimised Approach
# concatenate the array to the same array (ex : [3,4,5,1,2,3,4,5,1,2], to access just i%len which point to the original array index, so no need to store it in new array)
# introduce count = 1, then run the loop from 1 to 2*length
# increment count when arr[(i+1)%lenth] > arr[i%len] else set count to 1 
# when count = len retuen true else false

class Solution:
    def check(self, nums):
        l = len(nums)
        count = 1
        if l ==1: return True
        for i in range(1,2*l):
            if nums[i%l]<=nums[(i+1)%l]:
                count +=1
            else:
                count = 1
            if count == l:
                return True
        return False
        