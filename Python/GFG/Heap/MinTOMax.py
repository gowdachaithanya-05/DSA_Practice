# Convert Min Heap to Max Heap
# Difficulty: MediumAccuracy: 55.0%Submissions: 19K+Points: 4Average Time: 20m
# You are given an array arr of N integers representing a min Heap. The task is to convert it to max Heap.

# A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. 

# Example 1:

# Input:
# N = 4
# arr = [1, 2, 3, 4]
# Output:
# [4, 2, 3, 1]
# Explanation:

# The given min Heap:

#           1
#         /   \
#       2       3
#      /
#    4

# Max Heap after conversion:

#          4
#        /   \
#       2     3
#     /
#    1
# Example 2:

# Input:
# N = 5
# arr = [3, 4, 8, 11, 13]
# Output:
# [13, 11, 8, 3, 4]
# Explanation:

# The given min Heap:

#           3
#         /   \
#       4      8
#     /   \ 
#   11     13

# Max Heap after conversion:

#           13
#         /    \
#       11      8
#     /   \ 
#    3     4
 

# Your Task:
# Complete the function int convertMinToMaxHeap(), which takes integer N and array represented minheap as input and converts it to the array representing maxheap. You don't need to return or print anything, modify the original array itself.

# Note: Only an unique solution is possible under the expected time complexity.

# Expected Time Complexity: O(N * log N)
# Expected Auxiliary Space: O(N)


# Constraints:

# 1 <= N <= 105
# 1 <= arr[i] <= 109

#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    
    def heapify(self, arr, N , i):
        while (True):
            l = 2 * i + 1
            r = 2 * i + 2
            m = i 
            if l < N and arr[l] > arr[m]:
                m = l
            
            if r < N and arr[r] > arr[m]:
                m = r
            
            if m == i:
                break
            
            arr[i], arr[m] = arr[m] , arr[i]
            i = m 
    
    def convertMinToMaxHeap(self, N, arr):
       # Code here
        for i in range(N//2-1, -1, -1):
            self.heapify(arr, N, i)
            
            
            


#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        ob.convertMinToMaxHeap(N, arr)
        for val in arr:
            print(val, end = ' ')
        print()
        print("~")
# } Driver Code Ends