t=input()
for i in range(0,t):
	x=raw_input().split()
	n=int(x[0])
	m=int(x[1])
	calc=1
	for j in range(0,n-1):
		calc=calc*10+1;
	calc1=calc%m
	print calc1
