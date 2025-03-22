# 215. Kth Largest Element in an Array
# Solved
# Medium
# Topics
# Companies
# Facebook
# Amazon
# LinkedIn
# Microsoft
# Google
# Given an integer array nums and an integer k, return the kth largest element in the array.

# Note that it is the kth largest element in the sorted order, not the kth distinct element.

# Can you solve it without sorting?

 

# Example 1:

# Input: nums = [3,2,1,5,6,4], k = 2
# Output: 5
# Example 2:

# Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
# Output: 4
 

# Constraints:

# 1 <= k <= nums.length <= 105
# -104 <= nums[i] <= 104
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 2.9M
# Submissions
# 4.2M
# Acceptance Rate
# 67.7%

class Solution(object):

    def heapify(self, nums, n , i):
        while(True):
            l = 2*i + 1 # calculating index of left child for index node i 
            r = 2*i +2 # calculating index of right child for index node i 
            large = i # assuming parent is greater element
            if l < n and nums[l] > nums[large]: # check if left node exist and check if greater then the parent
                large = l # if yes update the large variable
            if r < n and nums[r] > nums[large]: # do the same with right node
                large = r

            if large == i: # if no chnage no need of swapping
                break

            nums[i], nums[large] = nums[large], nums[i]
            i = large # update i for next iteration
        
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        for i in range(n// 2-1, -1, -1):
            self.heapify(nums,n, i)

        for i in range(n-1, 0, -1):
            nums[0], nums[i] = nums[i], nums[0]
            self.heapify(nums, i, 0)

        return nums[n-k] 