import random
n=20
m=100000
print n,m
for i in range(0,n):
	val=random.randint(1,100)
	print val,
print " "
for i in range(0,m):
	p=random.randint(1,n-1)
	q=random.randint(p+1, n)
	print p,q
