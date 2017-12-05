count = 0
with open('input', 'r') as f:
    for line in f:
        a = True
        words = line.split()
        words_sorted = []

        for x in words:
            b = sorted(x)
            c = ''.join(b)
            words_sorted.append(c)

        for x in words_sorted:
            if(words_sorted.count(x) > 1):
                a = False
        if(a == True):
            count = count + 1

print(count)
