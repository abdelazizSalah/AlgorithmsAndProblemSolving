s = input("Enter First Word: ")
t = input("Enter Second Word: ")

charCounter = {}
for c in s:
    if c not in charCounter:
        charCounter[c] = 1
    else:
        charCounter[c] += 1

for c in t:
    if c not in charCounter:
        print(c)
        break
    else:
        charCounter[c] -= 1

for c in charCounter:
    if charCounter[c] != 0:
        print(c)
        break
