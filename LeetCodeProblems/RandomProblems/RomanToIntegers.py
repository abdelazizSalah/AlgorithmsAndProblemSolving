myMap = {
    'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
    'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900
}

s = input('insert the RomanDigit: ')
sum = 0
i = 0
while i < len(s):
    if(i != len(s) - 1):
        word = s[i] + s[i+1]
        if word in myMap:
            sum += myMap[word]
            i += 2
            continue
    sum += myMap[s[i]]
    i += 1

print(sum)
