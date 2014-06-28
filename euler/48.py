def power(x,y):
	s=1
	while y!=0:
		if y%2==1:
			s=s*x
			s%=10000000000
		x=x*x
		x%=10000000000
		y/=2
	return s
s=0
for i in range(1,1001):
	s+=power(i,i)
	s%=10000000000
print s
