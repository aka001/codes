import sys
import random
a=random.randint(1,100)
print a
for i in range(0,a):
	b=random.randint(1,50)
	c=random.randint(1,50)
	print b,c
	for j in range(0,b):
		for k in range(0,c):
			d=random.randint(0,1)
			if(d==0):
				sys.stdout.write('^')
			else:
				sys.stdout.write('#')
		print
