def reverse_sublist(lst, start, end):
    if(start > end):
        changes = int((len(lst) - start + end) / 2)
        for x in range(0, changes):
            aux = lst[start + x]
           # print(aux)
            lst[start + x] = lst[end - x]
            # print(aux)
            lst[end - x] = aux
    else:
        changes = int((end - start) / 2)
        for x in range(0, changes):
            aux = lst[start + x]
            # print(aux)
            lst[start + x] = lst[end - x]
            # print(aux)
            lst[end - x] = aux
    return lst

commands = [3, 4, 1, 5]

n = [0, 1, 2, 3, 4]
cp = 0
ss = 0
for lenght in commands:
    start = cp
    end = (start + (lenght - 1)) % len(n)
    print(start)
    print(end)
    n = reverse_sublist(n, start, end)
    print(n)
    cp = (cp + ss + lenght) % len(n)
    ss = ss + 1
