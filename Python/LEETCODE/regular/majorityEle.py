# 169. Majority Element
# Solved
# Easy
# Topics
# Companies
# Amazon
# Microsoft
# Adobe
# Apple
# Google
# Given an array nums of size n, return the majority element.

# The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

# Example 1:

# Input: nums = [3,2,3]
# Output: 3
# Example 2:

# Input: nums = [2,2,1,1,1,2,2]
# Output: 2
 

# Constraints:

# n == nums.length
# 1 <= n <= 5 * 104
# -109 <= nums[i] <= 109
 

# Follow-up: Could you solve the problem in linear time and in O(1) space?

#Hash Table, Time - O(n), Space = O(n)

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        
        m = max(d, key=d.get)
        
        return m


# count and sort

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        count = 0
        m = nums[0]
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                count +=1
                num = nums[i]
            else:
                count = 1
            
            if count > len(nums)//2:
                m = nums[i]
                break

        return m
        
# Boyer-Moore Voting Algorithm , Time - O(n), Space - O(1)

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = None
        count = 0 
        for num in nums:
            if count == 0:
                m = num
            if num == m:
                count +=1
            else:
                count -=1
        return m
            
