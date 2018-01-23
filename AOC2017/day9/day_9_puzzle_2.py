import re


input = ""
with open('input', 'r') as f:
    input = f.read().replace('\n', '')

input = re.sub(r"\!.", "", input)  # delete ignored stuff
#input = re.sub(r"\,", "", input)

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

totalCount = 0
for deletion in reversed(deletions):

    totalCount = totalCount + deletion[1] - 1 - deletion[0]
    input = input[:deletion[0]] + input[deletion[1] + 1:]
print(totalCount)