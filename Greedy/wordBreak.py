s = 'catsandog'
wordDict = ["cats", "dog", "sand", "and", "cat"]

for word in wordDict:
    if not s.startswith(word):
        print(False)
        exit(-1)
    else:
        s = s.removeprefix(word)

print(True)
