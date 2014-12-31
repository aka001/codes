def doit(x):
	x1=x
	s=0
	for i in range(1,100):
		if x==0:
			break
		p=x%10
		s+=p**5
		x/=10
	if s==x1:
		return True
	else:
		return False
for i in range(1,10000000):
	if doit(i):
		print i
