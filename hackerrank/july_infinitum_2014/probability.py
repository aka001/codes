def gcd(a,b):
	if(a==0):
		return b
	return gcd(b%a,a)
t=input()
for i in range(0,t):
	valit=[]
	valit1=[]
	listit1=[]
	strit1=[]
	listit=[]
	strit=[]
	cnt=0
	tnk=raw_input().split()
	n=int(tnk[0])
	k=int(tnk[1])
	val=input()
	if(val==0):
		valit.append(0)
	while(val!=0):
		calc=val%10
		valit.append(calc)
		val/=10
	calc1=0
	for j in range(0,n):
		listit1.append(valit[n-j-1])
	for j in range(0,n):
		if(listit1[j]==1):
			cnt+=1
		strit1.append(cnt)
	listit=listit1
	strit=strit1
	for j in range(0,n):
		if(listit[j]==1):
			val=j+k
			if(val>=n):
				val=n-1
			garb=strit[val]-strit[j]+1
			#print garb
			calc1+=2*garb-1
	if(calc1==0):
		print "0/1"
	else:
		calc2=1
		for j in range(0,n):
			calc2*=2
			gcdit=gcd(calc1,calc2)
			calc1/=gcdit
			calc2/=gcdit
		#print calc1,calc2
		gcdit=gcd(calc1,calc2)
		#print gcdit
		calc1/=gcdit
		calc2/=gcdit
		print str(calc1)+"/"+str(calc2)
