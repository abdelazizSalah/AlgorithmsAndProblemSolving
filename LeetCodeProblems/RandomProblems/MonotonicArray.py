from numpy import sign
arr = input('insertArr: ').split(' ')
def convertInt(x): return [int(i) for i in x]


arr = convertInt(arr)
if len(arr) == 1:
    print(True)
else:
    sgn = sign(arr[1] - arr[0])
    for i in range(1, len(arr)):
        newSign = sign(arr[i] - arr[i-1])
        if sgn == 0:
            sgn = newSign
            continue
        if(newSign == 0):
            continue
        else:
            if(sgn == -newSign):
                print(False)
                break

    print(True)
