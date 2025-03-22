# Binary Heap Operations
# Difficulty: MediumAccuracy: 22.3%Submissions: 104K+Points: 4Average Time: 15m
# A binary heap is a Binary Tree with the following properties:
# 1) Its a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

# 2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

# You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
# 1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
# 2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
# 3) 3  (a query like this removes the min element from the min-heap and prints it ).

# Examples :

# Input: 
# Q = 7
# Queries:
# insertKey(4)
# insertKey(2)
# extractMin()
# insertKey(6)
# deleteKey(0)
# extractMin()
# extractMin()
# Output: [2, 6, -1]
# Explanation: In the first test case for
# query 
# insertKey(4) the heap will have  {4}  
# insertKey(2) the heap will be {2 4}
# extractMin() removes min element from 
#              heap ie 2 and prints it
#              now heap is {4} 
# insertKey(6) inserts 6 to heap now heap
#              is {4 6}
# deleteKey(0) delete element at position 0
#              of the heap,now heap is {6}
# extractMin() remove min element from heap
#              ie 6 and prints it  now the
#              heap is empty
# extractMin() since the heap is empty thus
#              no min element exist so -1
#              is printed.
# Input:
# Q = 5
# Queries:
# insertKey(8)
# insertKey(9)
# deleteKey(1)
# extractMin()
# extractMin()
# Output: [8, -1]
# Constraints:
# 1 <= Q <= 104
# 1 <= x <= 104

# Company Tags
# AmazonMicrosoftSamsungOla CabsWalmartSynopsys

# User function Template for python3

'''
heap = [0 for i in range(101)]  # our heap to be used
'''

# Function to insert a value in Heap.
def insertKey(x):
    global curr_size
    heap[curr_size] = x  # Insert at the end
    i = curr_size
    curr_size += 1
    shiftUp(i)  # Restore heap property

# Function to delete a key at index i.
def deleteKey(i):
    global curr_size
    if i >= curr_size:
        return  # Index out of range
    decreaseKey(i, float('-inf'))  # Replace with -∞
    extractMin()  # Extract minimum (now at root)

# Function to extract the minimum value in heap and store 
# next minimum value at first index.
def extractMin():
    global curr_size
    if curr_size == 0:
        return -1  # If heap is empty
    min_val = heap[0]
    heap[0] = heap[curr_size - 1]  # Move last element to root
    curr_size -= 1
    shiftDown(0)  # Restore heap property
    return min_val

# Helper function to move an element up (heapify-up)
def shiftUp(i):
    while i > 0 and heap[(i - 1) // 2] > heap[i]:
        heap[(i - 1) // 2], heap[i] = heap[i], heap[(i - 1) // 2]
        i = (i - 1) // 2  # Move to parent

# Helper function to move an element down (heapify-down)
def shiftDown(i):
    global curr_size
    min_index = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < curr_size and heap[left] < heap[min_index]:
        min_index = left
    if right < curr_size and heap[right] < heap[min_index]:
        min_index = right
    if min_index != i:
        heap[i], heap[min_index] = heap[min_index], heap[i]
        shiftDown(min_index)

# Helper function to decrease the key at index i to a new value
def decreaseKey(i, new_val):
    heap[i] = new_val
    shiftUp(i)  # Restore heap property



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

# Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

heap = []  # our heap to be used
curr_size = 0  # current size of heap

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        # initialize every globals
        curr_size = 0
        heap = [0 for i in range(n)]
        i = 0
        while i < len(a):
            if a[i] == 1:
                insertKey(a[i + 1])
                i += 1
            elif a[i] == 2:
                deleteKey(a[i + 1])
                i += 1
            else:
                print(extractMin (), end=" ")
            i += 1
        # reinitialize every globals
        # curr_size = 0
        # heap = [0 for i in range(101)]
        print()
        print("~")
# } Driver Code Ends