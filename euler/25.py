def digcount(num):
	cnt=0
	while num!=0:
		cnt+=1
		num/=10
	return cnt
a=1
b=1
cntit=3
while 1:
	c=a+b
	a=b
	b=c
	if digcount(c)>=1000:
		print cntit
		break
	cntit+=1
