a=1<<1000
s=0
for i in range(1,1000):
	s=s+a%10
	a/=10
	if(a==0):
		break
print s
