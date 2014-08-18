import random
n=10**5
print n
a=[]
x=10**16
for i in range(0,n):
	a.append(x)
lenit=len(a)
for i in range(0,lenit):
	if(i!=lenit-1):
		print a[i],
	else:
		print a[i]
q=10**5
print q
for i in range(0,q):
	a=[]
	a.append(1)
	a.append(q)
	val=random.randint(0,10000000000000000)
	a.append(val)
	for j in (0,2):
		print a[j],
	print a[2]
