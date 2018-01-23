import sys
nodes = []
for line in sys.stdin:
    for var in line.split():
        var = var.replace(",", "")
        if(var[0:1] != "("):
            nodes.append(var)

for var in nodes:
    if(nodes.count(var) == 1):
        print(var)
