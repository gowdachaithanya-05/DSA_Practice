def highest_frequency(arr):
    arr.sort()  # Step 1: Sort the array
    max_freq = 0
    f = 0  # Frequency counter
    num = None  # To store the number with the highest frequency
    
    for i in range(len(arr) - 1):
        if arr[i] == arr[i + 1]:  # If the current and next elements are the same
            f += 1
        else:
            f = 0  # Reset frequency counter if elements are not the same
        
        if f > max_freq: 
            max_freq = f
            num = arr[i]
    
    return num, max_freq + 1

# Example Usage
arr = [4, 5, 6, 4, 4, 6, 6, 6, 5]
result = highest_frequency(arr)
print(f"Number with highest frequency: {result[0]}, Frequency: {result[1]}")
