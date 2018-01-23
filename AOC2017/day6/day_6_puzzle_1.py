import copy
a = [11, 11, 13, 7, 0, 15, 5, 5, 4, 4, 1, 1, 7, 1, 15, 11]
f = []

b = True
count = 0
while b:
    c = max(a)
    d = a.index(c)
    a[d] = 0
    e = True
    # rearrange
    while e:
        d = d + 1
        if(c != 0):
            c = c - 1
            a[d % (len(a))] = a[d % (len(a))] + 1
        else:
            e = False
    # verify if its bugged
    count = count + 1
    if(f.count(a) != 0):
        print(count)
        b = False
    else:
        g = copy.copy(a)
        f.append(g)