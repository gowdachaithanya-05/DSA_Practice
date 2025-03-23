def swap(lst, i, j): # Swap function to swap numbers
    lst[i], lst[j] = lst[j], lst[i]

def moveDown(lst, n, i):
    
    while(True):
        l = 2*i + 1 # calculating index of left child for index node i 
        r = 2*i +2 # calculating index of right child for index node i 
        large = i # assuming parent is greater element
        if l < n and lst[l] > lst[large]: # check if left node exist and check if greater then the parent
            large = l # if yes update the large variable
        if r < n and lst[r] > lst[large]: # do the same with right node
            large = r

        if large == i: # if no chnage no need of swapping
            break

        swap(lst, i, large) # replace parent node with greater element 
        i = large # update i for next iteration 
    
def heapSort(lst):
    n = len(lst)
    for i in range(n//2-1, -1, -1): # build heap 
        moveDown(lst,n,i)
    for i in range(n-1, 0, -1): # sorting
        swap(lst, 0, i) # swap the root node with the last 
        moveDown(lst, i, 0) # maintain heap property for new root 

lst = [67, 8, 9, 4, 1, 88]
heapSort(lst)
print(lst)