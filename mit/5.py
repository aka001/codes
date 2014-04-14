import sys
ar=[]
a=1
b=1
c=2
ar.append(a)
ar.append(b)
ar.append(c)
for i in range(1,10000000):
	a=b
	b=c
	c=a+b
	ar.append(c)
	if(len(str(c)) == 1001):
		break
for i in range(1,10000000):
	a=input()
	if(a==0):
		break
	a-=1
	print ar[a]
