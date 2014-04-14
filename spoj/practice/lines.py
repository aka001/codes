for i1 in range(0,10000000):
	n=input()
	if n==0:
		break
	a=[]
	x=[]
	y=[]
	for i in range(0,n):
		inp=raw_input().split()
		x.append(int(inp[0]))
		y.append(int(inp[1]))
	length=len(x)
	for i in range(0,length):
		p=x[i]
		q=y[i]
		for j in range(i+1, length):
			r=x[j]
			s=y[j]
			if r-p==0:
				m=-100000000
			else:
				m=(s-q)/((r-p)*1.0)
			if m not in a:
				a.append(m)
	print len(a)
