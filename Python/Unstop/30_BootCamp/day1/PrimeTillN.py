# Problem Statement
# King Luther has an army with N soldiers, each with an ID between 1 and N. The king wants to know how many soldiers in his army are "brave."

# A soldier is considered "brave" if their ID has exactly two factors (or Divisors) and is not a perfect square.

# Since King Luther is busy with his duties, he needs your help to count the number of "brave" soldiers in his army.

# Your task is to count how many soldiers have "brave" IDs according to the criteria.

# Input Format
# The input contains only one integer N denoting the number of soldiers in the army.

# Output Format
# Print the count of brave soldiers in the army.

# Constraints
# 1 ≤ N ≤ 10^6

# Sample Testcase 0
# Testcase Input
# 20
# Testcase Output
# 8
# Explanation
# Only 8 numbers from 1 to 20 follow the brave criteria those are : 


# 2, 3, 5, 7, 11, 13, 17, 19.


# It can be shown no number other than these follows the brave criteria.

# Sample Testcase 1
# Testcase Input
# 100
# Testcase Output
# 25
# Explanation
# Only 25 numbers from 1 to 100 follow the brave criteria those are : 


# 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97. 


# It can be shown no number other than these follows the brave criteria

#Brute Force Approach

def count_brave_soldiers(n):
    """
    Write your logic here.
    Parameters:
        n (int): The number of soldiers in the army
    Returns:
        int: The count of brave soldiers
    """
    count = 0
    for j in range(1,n+1):
        if j < 2:
            continue
        else:
            for i in range(2, int(j**0.5)+1):
                if j % i ==0:
                    break
            else:
                count +=1        

    pass
    return count

def main():
    import sys
    input = sys.stdin.read
    n = int(input().strip())  # The input contains only one integer N
    
    # Call the user logic function and print the output
    result = count_brave_soldiers(n)
    print(result)

if __name__ == "__main__":
    main()

# Optimised 
def count_brave_soldiers(n):
    """
    Write your logic here.
    Parameters:
        n (int): The number of soldiers in the army
    Returns:
        int: The count of brave soldiers
    """
    if n < 2:
        return 0
    prime = [True] * (n+1)
    prime[0] = prime[1] = False
    for i in range(2, int(n**0.5) + 1): 
        if prime[i]: 
            for j in range(i * i, n + 1, i):  
                prime[j] = False
    pass
    return sum(prime)

def main():
    import sys
    input = sys.stdin.read
    n = int(input().strip())  # The input contains only one integer N
    
    # Call the user logic function and print the output
    result = count_brave_soldiers(n)
    print(result)

if __name__ == "__main__":
    main()