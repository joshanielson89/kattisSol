import sys

firstLine = True
numTemps = 0
below = 0

for line in sys.stdin:
	ab = line.split()
	if firstLine:
		numTemps = int(ab[0])
		firstLine = False
	else:
		for i in range(numTemps):
			if int(ab[i]) < 0:
				below +=1
			i += 1
		print(below)