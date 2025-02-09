# 136. Single Number
# Solved
# Easy
# Topics
# Companies
# Hint
# Amazon
# Microsoft
# Bloomberg
# Google
# Adobe
# Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

# You must implement a solution with a linear runtime complexity and use only constant extra space.

 

# Example 1:

# Input: nums = [2,2,1]

# Output: 1

# Example 2:

# Input: nums = [4,1,2,1,2]

# Output: 4

# Example 3:

# Input: nums = [1]

# Output: 1

 

# Constraints:

# 1 <= nums.length <= 3 * 104
# -3 * 104 <= nums[i] <= 3 * 104
# Each element in the array appears twice except for one element which appears only once.


# Bit manipulation - Most optimal Solution , time = O(n), space = O(1)
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in nums:
            res = res ^ i  #XOR with itself gives 0, with 0 gives itself(Same number gets elemenated)
        return res

# Dictionary Solution (Same as map in cpp), time = O(n), space = O(n)

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        for num in nums:
            if num in d:
                d[num] +=1
            else:
                d[num] = 1
            
        for num, count in d.items():
            if count == 1:
                return num 

# Using set , time = O(n), space = O(n)

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = set()
        for num in nums:
            if num in res:
                res.remove(num)
            else:
                res.add(num)

        return res.pop()


#Sorting - not so optimal because of sorting, , time = O(nlogn), space = O(1)
    
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
       
        nums.sort() 
        
        for i in range(0, len(nums) - 1, 2):
            if nums[i] != nums[i + 1]:
                return nums[i]
        
        return nums[-1] # if last element is single 
