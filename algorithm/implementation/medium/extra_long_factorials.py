#!/bin/python3

import sys


n = int(input().strip())
s = n
for idx in range(n):
	if(idx != 0):
		s = s * (n-idx)

print(s)
