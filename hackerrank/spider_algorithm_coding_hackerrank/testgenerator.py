import random
k=100
n=30
print n,k
a=[]
for i in range(0,n):
	while(1):
		val=random.randint(0,100)
		if(val not in a):
			a.append(val)
			break
	print a[i]
