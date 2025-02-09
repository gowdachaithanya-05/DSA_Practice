# 75. Sort Colors
# Solved
# Medium
# Topics
# Companies
# Hint
# Microsoft
# Amazon
# VMware
# Adobe
# Salesforce
# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

# We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

# You must solve this problem without using the library's sort function.

 

# Example 1:

# Input: nums = [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]
# Example 2:

# Input: nums = [2,0,1]
# Output: [0,1,2]
 

# Constraints:

# n == nums.length
# 1 <= n <= 300
# nums[i] is either 0, 1, or 2.
 

# Follow up: Could you come up with a one-pass algorithm using only constant extra space?


#Bubble Sort

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] > nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]

# Using count, Time = O(n+n), Space - O(1)

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        c1,c2,c3 = 0, 0, 0
        for i in range(len(nums)):
            if nums[i] == 0:
                c1 +=1
            elif nums[i]==1:
                c2 +=1
            else:
                c3 +=1
           
        for i in range(c1):
            nums[i] = 0
        for i in range(c1, (c1+c2)):
            nums[i] = 1
        for i in range(c1+c2, len(nums)):
            nums[i] = 2




# Dutch National Flag Algorithm, Time - O(n), Space - O(1)- One pass alogorithm 
#Step1: one initialise three pointers low and mid to 0 and high
#Step2: traverse through nums using mid, if mid = 0 swap with low, increment low and mid 
#Step3: If 1 just increment mid
#Step4:  if mid =2 swap it with high and decremnet i, do not increment mid because swapped value could be 0 hence has to swapped back to left
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l, m, h = 0, 0, len(nums) - 1

        for i in range(len(nums)):
            if nums[m] == 0:
                nums[l], nums[m] = nums[m], nums[l]
                l +=1
                m +=1
            elif nums[m] == 1:
                m +=1
            else:
                nums[h], nums[m] = nums[m], nums[h]
                h -=1
