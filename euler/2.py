a=1
b=2
s=2
for i in range(1,1000000):
	c=a+b
	a=b
	b=c
	if c>4000000:
		break
	if(c%2==0):
		s+=c
print s
