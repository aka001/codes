t=input()
for i in range(0,t):
	a=input()
	x=2
	i=6
	c=3
	cnt=1
	x=x%a
	while x!=0:
#print cnt,x,i
		x*=i
		i*=(c+1)
		c+=1
		x=x%a
		cnt+=1
	print cnt
