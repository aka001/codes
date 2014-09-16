arr=[]
primeit=[]
arr.append(0)
arr.append(0)
maxit=100006
for i in range(2,maxit+4):
	arr.append(1)
i=4
for i in range(4,maxit+4,2):
	arr[i]=0
i=3
while(i*i<=maxit):
	if(arr[i]==1):
		j=i*i
		while(j<=maxit):
			arr[j]=0
			j+=2*i
	i+=2
for i in range(2,maxit):
	if(arr[i]==1):
		primeit.append(i)
limitit1 = len(primeit)
t=raw_input().split()
t=t[0]
t=int(t)
for i in range(0,t):
	printit=[]
	val=raw_input().split()
	val=val[0]
	val=int(val)
	'''if val==1:
		print "0"
	else:
		print "1"
		print val'''
	calc=primeit[0]
	j=0
	limitit=5000
	while(j<limitit):
		calc=primeit[j]
		while(val%calc==0):
			printit.append(calc)
			val/=calc
		if(val<limitit1):
			if(val==1 or arr[val]==1):
				break
		j+=1
	if(val!=1):
		printit.append(val)
	sizeit=len(printit)
	print sizeit
	for j in printit:
		print j
