count = 0
with open('input', 'r') as f:
    for line in f:
        a = True
        words = line.split()
        for x in words:
            if(words.count(x) > 1):
                a = False
        if(a == True):
            count = count + 1

print(count)
