import sys
commands = []
for line in sys.stdin:
    commands.append(line.split())

memory = {}
biggest = 0
for command in commands:
    currMemory = command[0]
    currInstruction = command[1]
    currValue = command[2]

    currIfMemory = command[4]
    currIfOperator = command[5]
    currIfValue = command[6]

    if(currMemory not in memory):
        memory[currMemory] = 0

    if(currIfMemory not in memory):
        memory[currIfMemory] = 0

    valueIfInMemory = memory[currIfMemory]
    possible = False
    if(currIfOperator == "!="):
        if(valueIfInMemory != int(currIfValue)):
            possible = True
    if(currIfOperator == ">="):
        if(valueIfInMemory >= int(currIfValue)):
            possible = True
    if(currIfOperator == ">"):
        if(valueIfInMemory > int(currIfValue)):
            possible = True
    if(currIfOperator == "<"):
        if(valueIfInMemory < int(currIfValue)):
            possible = True
    if(currIfOperator == "<="):
        if(valueIfInMemory <= int(currIfValue)):
            possible = True
    if(currIfOperator == "=="):
        if(valueIfInMemory == int(currIfValue)):
            possible = True

    if(possible):
        if(currInstruction == "dec"):
            memory[currMemory] = memory[currMemory] - int(currValue)
        else:
            memory[currMemory] = memory[currMemory] + int(currValue)


for key, value in memory.items():
    if(value > biggest):
        biggest = value

print(biggest)
