def bubble(arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr

arr = [6, 88, 98, 4,3,9]
arr = bubble(arr)
print(arr)