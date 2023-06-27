import numpy as np
indcies = []
startGene = 'AACCGGTT'
endGene = 'AACCGGTA'
bank = ["AACCGGTA"]
if endGene not in bank:
    exit(-1)
for i in range(8):
    if startGene[i] != endGene[i]:
        indcies.append(i)

changes = len(indcies)

while changes != 0:
    canChange = False
    for indx in indcies:
        originalChar = startGene[indx]
        newGene = ''
        for i in range(8):
            if i != indx:
                newGene += startGene[i]
            else:
                newGene += endGene[i]
        if newGene in bank:
            changes -= 1
            canChange = True
            startGene = newGene
            if changes == 0:
                break
        else:
            pass  # nothing happens
    if not canChange:
        exit(-1)

print(len(indcies))
