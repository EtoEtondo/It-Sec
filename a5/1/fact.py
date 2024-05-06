#!/usr/bin/python

import sys

def usage():
  print "Usage: factorize.py <n> <varphi>"
  sys.exit(1);


def factorp(n, phin):
  z = n - phin
  x = (z+1)**2
  y = x - 4*n
  return int(( x**(0.5) + y**(0.5) ) / 2)

# Main
if len(sys.argv) != 3: usage()

n     = int(sys.argv[1])
phin  = int(sys.argv[2]) 

p = factorp(n, phin)

print p, n/p
