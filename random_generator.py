import random
import sys


if (len(sys.argv) != 2):
	total_numbers = 10
else:
	total_numbers = int(sys.argv[1])
numberlist = range(0, total_numbers + 1)
random.shuffle(numberlist)
outputstring = ""
for i in numberlist:
	outputstring += str(i) + " "
sys.stdout.write(outputstring[:-1])


try:
    sys.stdout.close()
except:
    pass
try:
    sys.stderr.close()
except:
    pass