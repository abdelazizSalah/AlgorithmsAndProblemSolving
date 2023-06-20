word1 = input("Enter First Word: ")
word2 = input("Enter Second Word: ")
minLen = min(len(word1), len(word2))
newString = ""
# word1 is shorter
for i in range(minLen):
    newString += word1[i]
    newString += word2[i]

if len(word1) == minLen:
    newString += word2[minLen:]
else:
    # word2 is shorter
    newString += word1[minLen:]

print(newString)
