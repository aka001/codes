import random
print "1"
n=1000
print n
x=[]
for i in range(0,n):
	for i in range(0,1000000):
		a=random.randint(1,n)
		if a not in x:
			x.append(a)
			break
for i in x:
	print i,
