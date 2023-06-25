up, right = 0, 0

inp = input('insert the string: ')
for c in inp:
    if c == 'U':
        up += 1
    elif c == 'D':
        up -= 1
    elif c == 'L':
        right -= 1
    else:
        right += 1

print(up == right == 0)
