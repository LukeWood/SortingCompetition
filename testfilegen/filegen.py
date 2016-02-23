import sys

with open(sys.argv[1], "w+") as f:
	for i in range(0,int(sys.argv[2])):
		chartowrite = (i % 221)+34
		length = int(i/10)
		towrite = ""
		for j in range(0, length + 1):
			nextc = (((chartowrite+j)%221)+34)
			if(nextc < 255 and nextc > 0):
				towrite+=str(chr(nextc))
		f.write(towrite + '\n')
	f.close()
