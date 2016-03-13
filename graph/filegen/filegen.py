import random
import string
numwords = 125000
fname = str(numwords) + ".txt"
for a in range(1,15):
	with open(fname,"w+") as f:
		f.write(str(numwords))
		f.write('\n')
		for i in range(0,numwords):
			toprint = ""
			for j in range(0,random.randrange(1,80)):
				toadd = random.choice(string.ascii_letters)
				if(toadd != '\n'):
					toprint+=random.choice(string.ascii_letters)
			f.write(toprint)
			f.write('\n')
		f.close()
	numwords+=125000
	fname = str(numwords)+".txt"
