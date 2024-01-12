def halvesAreAlike( s: str) -> bool:
    sz = len(s)//2
    leftPart = s[:sz]
    rightPart = s[sz:]
    vowels = ['a','e','i','o','u','A','E','I','O','U']
    leftCounter, rightCounter = 0,0
    for i in range (sz):
        if leftPart[i] in vowels:
            leftCounter+=1
        if rightPart[i] in vowels:
            rightCounter+=1
    return leftCounter == rightCounter
halvesAreAlike(s ="book")
        