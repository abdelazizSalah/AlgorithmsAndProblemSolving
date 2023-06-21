s = input('enter the string: ')
subString = s[0]
can = False
for i in range(len(s) // 2 + 1):
    if len(subString) != len(s):
        can = True
        for j in range(len(subString), len(s), len(subString)):
            if s[j:].find(subString) != 0:
                subString += s[i+1]
                can = False
                break
    if can:
        break
print(can)
