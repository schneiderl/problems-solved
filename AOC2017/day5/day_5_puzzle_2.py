with open('input', 'r') as f:
    lines = []
    for line in f:
        lines.append(line)

    currPos = 0
    count = 0
    a = True
    while a:
        currMove = lines[currPos]
        if(int(currMove) >= 3):
            newOffset = int(lines[currPos]) - 1
            lines[currPos] = newOffset #not really sure why python gets crazy about doing this without a aux variable
        else:
            newOffset = int(lines[currPos]) + 1
            lines[currPos] = newOffset
        currPos = currPos + int(currMove)
        count = count + 1
        if(currPos > (len(lines) - 1) or currPos < 0):
            a = False
print(count)
