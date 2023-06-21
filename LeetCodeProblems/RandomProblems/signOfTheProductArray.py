from functools import reduce
from numpy import sign
sz = input('Enter the size of the array: ')
sz = int(sz)
arr = []
for i in range(sz):
    arr.append(int(input('Enter the element: ')))

result = reduce(lambda x, y: x*y, arr)
print(sign(result))
