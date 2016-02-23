import sys

with open(sys.argv[1], "w+") as f:
	for i in range(0,int(sys.argv[2])):
		chartowrite = (i % 221)+32
		length = int(i/10)
		towrite = ""
		for j in range(0, length + 1):
			nextc = (((chartowrite+j)%221)+32)
			if(nextc < 255 and nextc > 0):
				towrite = towrite + str(chr(nextc))
		print(towrite)
		f.write(towrite + '\n')
	f.close()
