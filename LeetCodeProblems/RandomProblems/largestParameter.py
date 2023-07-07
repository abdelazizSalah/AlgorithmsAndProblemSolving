sideLen = [1, 2, 1, 10]
primeters = [0]


def possibleSides(s1, s2, s3):
    return s1 + s2 > s3 and s1 + s3 > s2 and s2 + s3 > s1


sz = len(sideLen)
sideLen = sorted(sideLen)
for i in range(sz - 1, 1, -1):
    if possibleSides(sideLen[i], sideLen[i-1], sideLen[i-2]):
        print(sideLen[i] + sideLen[i-1] + sideLen[i-2])
        exit(-1)


print(0)
