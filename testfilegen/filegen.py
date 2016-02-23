import sys

with open(sys.argv[1], "w+") as f:
	for i in range(0,int(sys.argv[2])):
		chartowrite = (i % 221)+34
		length = int(i/10)
		towrite = ""
		for j in range(0, length + 1):
			chartowrite = j
			towrite = towrite + str(chr(((chartowrite+j)%221)+34))
		f.write(towrite + '\n')
	f.close()
