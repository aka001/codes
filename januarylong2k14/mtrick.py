t=input()
for i in range(0,t):
	ar=[]
	n=input()
	x=raw_input().split()
	ar=[long(val) for val in x]
	x=raw_input().split()
	a=long(x[0])
	b=long(x[1])
	c=long(x[2])
	string=raw_input().split()
	string=string[0]
	lit=len(string)
	calc=0
	calc1=1
	for j in range(0,lit):
		if(string[j]=='A'):
			calc+=a
			if calc>c:
				calc%=c
		elif(string[j]=='M'):
			calc*=b
			calc1*=b
		if calc1>c:
			calc1%=c
		if calc>c:
			calc%=c
		if string[j]=='R':
			ar[j:]=reversed(ar[j:])
		ar[j]*=calc1
		if ar[j]>c:
			ar[j]%=c
		ar[j]+=calc
		if ar[j]>c:
			ar[j]%=c
#print calc, calc1
	for j in range(0,n-1):
		print ar[j]%c,
	print ar[n-1]%c
