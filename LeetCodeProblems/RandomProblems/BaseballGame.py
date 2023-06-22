from numpy import sum, floor
operations = input('Insert Operations: ').split(' ')
record = []

for op in operations:
    if op == '+':
        # add the last two scores
        record.append(record[-1] + record[-2])
    elif op == 'D':
        # The new record is double the previous one
        record.append(2 * record[-1])
    elif op == 'C':
        # remove last score
        record.remove(record[-1])
    else:
        record.append(int(op))

print(floor(sum(record)))
