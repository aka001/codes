import random
t=50
print t
for i in range(0,t):
	n=random.randint(2,8)
	print n
	li=[]
	for j in range(0,n-1):
		val=random.randint(1,100)
		print val,
	print random.randint(1,1000000)
