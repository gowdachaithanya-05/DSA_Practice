# Kth Smallest
# Difficulty: MediumAccuracy: 35.17%Submissions: 679K+Points: 4Average Time: 25m
# Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

# Follow up: Don't solve it using the inbuilt sort function.

# Examples :

# Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
# Output:  7
# Explanation: 3rd smallest element in the given array is 7.
# Input: arr[] = [2, 3, 1, 20, 15], k = 4 
# Output: 15
# Explanation: 4th smallest element in the given array is 15.
# Expected Time Complexity: O(n+(max_element) )
# Expected Auxiliary Space: O(max_element)
# Constraints:
# 1 <= arr.size <= 106
# 1<= arr[i] <= 106
# 1 <= k <= n

# Company Tags
# VMWareAccoliteAmazonMicrosoftSnapdealHikeAdobeGoogleABCOCisco

#User function Template for python3


class Solution:
    def heapify(self, arr, n , i):
        while(True):
            l = 2*i + 1 # calculating index of left child for index node i 
            r = 2*i +2 # calculating index of right child for index node i 
            small = i # assuming parent is greater element
            if l < n and arr[l] < arr[small]: # check if left node exist and check if greater then the parent
                small = l # if yes update the large variable
            if r < n and arr[r] < arr[small]: # do the same with right node
                small = r

            if small == i: # if no chnage no need of swapping
                break

            arr[i], arr[small] = arr[small], arr[i]
            i = small # update i for next iteration
        

    def kthSmallest(self, arr,k):
        
        n = len(arr)
        
        for i in range(n// 2-1, -1, -1):
            self.heapify(arr, n , i)
        
        for i in range(n-1, 0, -1):
            arr[0], arr[i] = arr[i], arr[0]
            self.heapify(arr, i , 0)
            
        return arr[n-k]
            



#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    import random
    t = int(input())
    for tcs in range(t):
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthSmallest(arr, k))
        print("~")
# } Driver Code Ends