def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,a%b)
maxit=100009
primeit=[]
isprime={}
for i in range(0,maxit+1):
	isprime[i]=0
isprime[0]=1
isprime[1]=1
isprime[2]=1
primeit.append(2)
for i in range(4,maxit,2):
	isprime[i]=1
sqrtit=maxit**0.5
sqrtit=int(sqrtit)+1
for i in range(3,sqrtit,2):
	if(isprime[i]==0):
		for j in range(i*i,maxit,2*i):
			isprime[j]=1
		primeit.append(i)	
t=input()
for i in range(0,t):
	n=input()
	primetrack=[]
	calcit=[]
	newit=[]
	for j in range(0,100001):
		primetrack.append(0)
	arr=[]
	dictit={}
	xx=raw_input().split()
	arr.append(0)
	dictit[0]=0
	for j in xx:
		val=int(j)
		arr.append(val)
		dictit[val]=0
	for j in range(1,n+1):
		if dictit[arr[j]]==0:
			dictit[arr[j]]=1
			x=arr[j]
			y=arr[x]
			cnt=1
			while(y!=x):
				cnt+=1
				dictit[y]=1
				y=arr[y]
			calcit.append(cnt)
	calcit.sort()
	sizeit=len(calcit)
	for j in range(0,sizeit):
		if(j==sizeit-1 or calcit[j]!=calcit[j+1]):
			newit.append(calcit[j])
	sizeit=len(newit)
	if(sizeit==1):
		print newit[0]
	else:
		calc=newit[0]
		modit=1000000007
		for i in range(1,sizeit):
			calc1=gcd(calc,newit[i])
			calc2=(calc*newit[i])/calc1
			calc=calc2
		calc%=modit
		print calc
