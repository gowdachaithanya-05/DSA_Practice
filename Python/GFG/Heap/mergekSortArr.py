# Merge k Sorted Arrays
# Difficulty: MediumAccuracy: 67.25%Submissions: 112K+Points: 4Average Time: 45m
# Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


# Examples :

# Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
# Output: 1 2 3 4 5 6 7 8 9
# Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
# Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
# Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
# Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
# Expected Time Complexity: O(k2*Log(k))
# Expected Auxiliary Space: O(k2)

# Constraints:
# 1 <= k <= 100

#User function Template for python3

import heapq
class Solution:
    #Function to merge k sorted arrays.
    pq = []
    def mergeKArrays(self, arr, K):
        # code here
        # return merged list
        for i in range(K):
            for j in range(K):
                heapq.heappush(self.pq, arr[i][j])
                
        
        res = []
        while self.pq:
            res.append(heapq.heappop(self.pq))
                
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        n=int(input())
        numbers=[[ 0 for _ in range(n) ] for _ in range(n) ]
        line=input().strip().split()
        for i in range(n):
            for j in range(n):
                numbers[i][j]=int(line[i*n+j])
        ob = Solution();
        merged_list=ob.mergeKArrays(numbers, n)
        for i in merged_list:
            print(i,end=' ')
        print()
        print("~")
# } Driver Code Ends

