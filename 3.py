

def parseData(filename):
    return [line.strip() for line in open('data/3.in')]


def solve(data):

    path = data[0]

    delivered = set()
    currentPos = (0, 0)
    moves = {'>': (1, 0), '^': (0, 1), '<': (-1, 0), 'v': (0, -1)}
    delivered.add(currentPos)

    for p in path:
        m = moves[p]
        currentPos = (currentPos[0]+m[0], currentPos[1] + m[1])
        delivered.add(currentPos)

    print("With only one Santa,", len(delivered),
          "houses receive at least 1 present")  # Part 1 answer

    deliveredReal = set()
    deliveredRobo = set()
    currentPos = (0, 0)
    roboPos = (0, 0)
    deliveredReal.add(currentPos)
    deliveredRobo.add(currentPos)

    for i, p in enumerate(path):
        m = moves[p]
        if i % 2 == 0:
            currentPos = (currentPos[0]+m[0], currentPos[1] + m[1])
            deliveredReal.add(currentPos)
        else:
            roboPos = (roboPos[0]+m[0], roboPos[1] + m[1])
            deliveredRobo.add(roboPos)

    print("With Santa and Robo-Santa,", len(deliveredReal.union(deliveredRobo)),
          "houses receive at least 1 present")  # Part 2 answer


if __name__ == '__main__':
    data = parseData('data/3.in')
    solve(data)
