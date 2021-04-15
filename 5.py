lines = [n for n in open('data/5.in')]


vowels = 'aeiou'
badStrings = ['ab', 'cd', 'pq', 'xy']
numNice = 0
for l in lines:

    vowelCount = sum([l.count(v) for v in vowels])

    doubleLetters = any([l[n] == l[n-1] for n in range(1, len(l))])

    badString = any([True if b in l else False for b in badStrings])

    if vowelCount >= 3 and doubleLetters and not badString:
        numNice += 1
        print(l, end="")

print(numNice)
