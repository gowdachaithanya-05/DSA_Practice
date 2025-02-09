# 485. Max Consecutive Ones
# Solved
# Easy
# Topics
# Companies
# Hint
# Google
# Apple
# Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

# Example 1:

# Input: nums = [1,1,0,1,1,1]
# Output: 3
# Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
# Example 2:

# Input: nums = [1,0,1,1,0,1]
# Output: 2
 

# Constraints:

# 1 <= nums.length <= 105
# nums[i] is either 0 or 1.

# OPtimised Solution - O(n)

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        m = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                count +=1
            else:
                m = max(count , m)
                count = 0
            m = max(count , m)

        return m

#Brute force Approach O(n^2)

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = 0
        for i in range(len(nums)):
            count = 0
            for j in range(i, len(nums)):
                if nums[j] == 1:
                    count +=1
                else:
                   break
            m = max(count, m)   

        return m