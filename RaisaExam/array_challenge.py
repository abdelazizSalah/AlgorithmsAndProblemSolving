def circular_rotate_array(arr, k):
    n = len(arr)
    k = k % n  # Handle the case when k is larger than the length of the array
    return arr[k:] + arr[:k]

# Example usage:
arr = [2,3,4,1,6,10]
k = 2
result = circular_rotate_array(arr, k)
# Convert the integers to strings
arr_str = [str(num) for num in result]

# Join the strings with a delimiter
output = ''.join(arr_str)  # You can use any delimiter you want

print("Array as a string:", output)
