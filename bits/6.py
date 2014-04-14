t=input()
a=[]
n=input()
for i in range(0,n):
	c=raw_input().split()
	d=c[0]
	if d == "UPDATE":
		e=int(c[1])
		f=int(c[2])
		a.append([e,f])
	else:
		e=int(c[1])
		l=len(a)
		calc=0
		calc=reduce(lambda x,y: x[1]+y[1], a for e%x[0]==0 and e%y[0]==0)
		print calc
