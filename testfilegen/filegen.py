import random
import string
numwords = 20000
with open("test.txt","w+") as f:
	f.write(str(numwords))
	f.write('\n')
	for i in range(0,numwords):
		toprint = ""
		#for j in range(0,random.randrange(1,80)):
		for j in range(0,50):
			toadd = random.choice(string.ascii_letters)
			if(toadd != '\n'):
				toprint+=random.choice(string.ascii_letters)
		f.write(toprint)
		f.write('\n')
	f.close()
