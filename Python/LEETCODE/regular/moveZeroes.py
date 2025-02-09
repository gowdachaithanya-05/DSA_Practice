# 283. Move Zeroes
# Solved
# Easy
# Topics
# Companies
# Hint
# Facebook
# Microsoft
# Apple
# Amazon
# Yandex
# Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

# Note that you must do this in-place without making a copy of the array.

 

# Example 1:

# Input: nums = [0,1,0,3,12]
# Output: [1,3,12,0,0]
# Example 2:

# Input: nums = [0]
# Output: [0]
 

# Constraints:

# 1 <= nums.length <= 104
# -231 <= nums[i] <= 231 - 1
 

# Follow up: Could you minimize the total number of operations done?

#Brute Force Approach
#use two loops when nums[i]=0, find non zero element nums[j], then swap them

           
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        for i in range(0, len(nums)-1):
            if nums[i] ==0:
                for j in range(i+1, len(nums)):
                    if nums[j] != 0 :
                        nums[j], nums[i] = nums[i], nums[j]
                        break
           


# Optimised 
# Approach : move all non zero elements to front then move zeros to end using two pointer 
# Step 1: iterate through list using for loop
# Step 2: if element is not zero, then nums[j] = nums[i] 
# Step 3: if element is moved to different place (i!=j), nums[i]=0 
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[j] = nums[i]

                if j!=i:
                    nums[i] = 0
                j +=1    
            
