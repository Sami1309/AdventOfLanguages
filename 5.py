# Shows how much easier data parsing stuff like this is in Python

lines = [n for n in open('data/5.in')]

vowels = 'aeiou'
badStrings = ['ab', 'cd', 'pq', 'xy']
numNice = 0
numNice2 = 0
for l in lines:

    vowelCount = sum([l.count(v) for v in vowels])

    doubleLetters = any([l[n] == l[n-1] for n in range(1, len(l))])

    badString = any([b in l for b in badStrings])

    pairRepeats = any([l[n] + l[n+1] in (l[0:n] or l[n+2:])
                      for n in range(len(l)-1)])

    sandwiches = any(l[n+2] == l[n] for n in range(len(l)-2))

    if vowelCount >= 3 and doubleLetters and not badString:
        numNice += 1
    if sandwiches and pairRepeats:
        numNice2 += 1

print(numNice)  # Part 1 solution
print(numNice2)  # Part 2 solution

# 17 something lines vs ~100
# C is masochistic for stuff like this
