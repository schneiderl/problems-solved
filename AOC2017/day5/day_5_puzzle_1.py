with open('input', 'r') as f:
    lines = []
    for line in f:
        lines.append(line)

    currPos = 0
    count = 0
    a = True
    while a:
        currMove = lines[currPos]
        lines[currPos] = 1 + int(lines[currPos])
        currPos = currPos + int(currMove)
        count = count + 1
        if(currPos > (len(lines) - 1) or currPos < 0):
            a = False
print(count)
