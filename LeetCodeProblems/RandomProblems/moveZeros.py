import numpy as np
sz = input('Enter the size of the array: ')
sz = int(sz)
arr = []
for i in range(sz):
    arr.append(int(input('Enter the element: ')))
# arr = np.array(arr)
# print(arr)

# for i in range(sz):
#     if(arr[i] == 0):
#         for j in range(i+1, sz):
#             if(arr[j] != 0):  # swap.
#                 arr[j], arr[i] = arr[i], arr[j]
#                 break
# print(arr)

# another faster solution
counter = 0  # this should count how many zeros we have passed by.
for i in range(len(arr)):
    if arr[i] == 0:
        counter += 1
    else:
        arr[i - counter] = arr[i]

counter = -counter
arr[counter:] = [0] * -counter
print(arr)
