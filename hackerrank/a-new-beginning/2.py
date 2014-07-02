import itertools
a=raw_input()
a=a.split()
a=a[0]
lenit=len(a)
x=[]
for i in range(1,lenit+1):
	for c in itertools.combinations(a,i):
		cc=''.join(c)
		x.append(cc)
x=sorted(x)
lenit=len(x)
y=[]
for i in range(0,lenit-1):
	if(x[i]!=x[i+1]):
		y.append(x[i])
y.append(x[lenit-1])
for i in y:
	print i
