#!/bin/python3

import sys
#Did this one in python because its easier
t = int(input().strip())
for a0 in range(t):
    b,w = input().strip().split(' ')
    b,w = [int(b),int(w)]
    x,y,z = input().strip().split(' ')
    x,y,z = [int(x),int(y),int(z)]

    res = 0;
    if(x==y):
    	res = b*x + w*y
    elif(x>y):
    	if((y+z)<x):
    		res = b*(y+z) + w*y
    	else:
    		res = b*x + w*y
    else:
    	if((x+z)<y):
    		res = b*x + w*(x+z)
    	else:
    		res = b*x + w*y

    print res