def selection(arr):
    for i in range(len(arr)):
        min = i
        for j in range(i+1, len(arr)):
            if arr [j] < arr[min]: 
                min = j    #update the min index to j (min value)
        arr[i], arr[min] = arr[min], arr[i] #swap current element with smallest element
    return arr
            
arr = [8, 8, 3, 2, 7, 6]
arr = selection(arr)
print(arr)