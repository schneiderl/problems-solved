
def count_down(n):
    s = 0
    for x in range(n):
        s = s + x * 2
    return(s)


def count_up(downCount, houseNumber):
    count = 0
    while (count < downCount):
        houseNumber = houseNumber + 1
        count = count + houseNumber * 2
    return count, houseNumber


def first_version(houseNumber):
    downCount = count_down(houseNumber)
    upCount, upHouse = count_up(downCount, houseNumber)
    if(downCount == upCount):
        print("houseNumber: " + str(houseNumber) +
              "      count:" + str(upHouse))
    elif ((houseNumber % 1000) == 0):
        print("not possible for house number " + str(houseNumber))


def first_version_iterator():
    houseNumber = 0
    while(True):
        houseNumber = houseNumber + 1
        first_version(houseNumber)

first_version_iterator()


# def second_version():
