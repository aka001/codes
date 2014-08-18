t=input()
for i in range(0,t):
	x=raw_input().split()
	y=int(x[1])
	x=int(x[0])
	x1=x
	s=x1
	for i in range(0,100):
		if(x<y):
			break
		x1=x/y
		x=x/y+x%y
		s+=x1
	print s


