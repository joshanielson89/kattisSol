import sys
 
for line in sys.stdin:
    ab = line.split()
    print (((2 ** ab[0]) + 1) ** 2)