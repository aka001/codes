import random
file=open('in1','w')
strit=""
for i in range(1,100000):
	strit+=str(random.randint(0,9))
file.write(strit)
file.close()
