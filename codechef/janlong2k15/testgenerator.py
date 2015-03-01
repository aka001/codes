import random
n=5
m=20
print n,m
s=""
for i in range(0,n):
	s+=str(random.randint(0,9))
print s
for i in range(0,m):
	val=random.randint(1,2)
	if(val==1):
		v1=random.randint(1,n)
		v2=random.randint(0,9)
	else:
		v1=random.randint(1,n)
		v2=random.randint(v1,n)
	print val,v1,v2
