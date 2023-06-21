from numpy import sort
arr = input('insertArr: ').split(',')
def convertInt(x): return [int(i) for i in x]


arr = convertInt(arr)
arr = sort(arr)

diff = arr[1] - arr[0]
can = True
for i in range(1, len(arr)):
    if(arr[i] - arr[i-1] != diff):
        can = False
        break
print(can)
