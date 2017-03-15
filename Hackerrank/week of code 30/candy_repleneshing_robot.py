def calculate_candy(icn_, t_, cc_):
    cn_ = icn_
    sadd = 0
    if t_ == 1:
        return 0
    for i in range(0, t_ - 1):
        cn_ = cn_ - cc_[i]
        if cn_ < 5:
            add = (icn_ - cn_)
            sadd = sadd + add
            cn_ = icn_
    return sadd

if __name__ == '__main__':
    icn, t = input().strip().split(' ')
    icn, t = [int(icn), int(t)]

    cc = list(map(int, input().strip().split(' ')))

    print(
        calculate_candy(icn, t, cc)
    )