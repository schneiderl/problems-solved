import re


input = ""
with open('input', 'r') as f:
    input = f.read().replace('\n', '')

input = re.sub(r"\!.", "", input)  # delete ignored stuff
input = re.sub(r"\,", "", input)

count = 0
idxEnd = 0
idxStart = 0
deletions = []
for c in input:
    if(c == "<"):
        if(idxEnd >= idxStart):
            idxStart = count
    if(c == ">"):
        idxEnd = count
        deletions.append([idxStart, idxEnd])
    count = count + 1


for deletion in reversed(deletions):
    input = input[:deletion[0]] + input[deletion[1] + 1:]

count = 0
totalCount = 0
for c in input:

    if(c == "{"):
        count = count + 1
        totalCount = totalCount + count
    else:
        count = count - 1

print(totalCount)
