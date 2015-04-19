import random
n=100000
m=10**8
x=random.randint(0,n-1)
y=random.randint(0,n-1)
print n
for i in range(0,n):
	val=random.randint(1,1000000000)
	if(i!=n-1):
		print val,
	else:
		print val
print m,x,y
