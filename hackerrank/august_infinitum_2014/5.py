import math
def powerit(a,b,c,chk):
	y=a
	res=1
	flagit=0
	while b!=0:
		val=b%2
		if(chk==1 and res>=c):
			flagit=1
			break
		if(chk==0 and res%c==0):
			flagit=2
			break
		if(val==1):
			res=res*y;
		b/=2
		#if(b==0):
		#	break
		y=y*y
	if(chk==0 and res%c==0):
		flagit=2
	if(flagit==1):
		return c+1
	elif flagit==2:
		return -1
	else:
		return res
n=input()
arr=[]
x=raw_input().split()
for j in x:
	arr.append(int(j))
q=input()
for i in range(0,q):
	x=raw_input().split()
	a=int(x[0])
	b=int(x[1])
	x=int(x[2])
	a-=1
	b-=1
	#print arr[a]
	#print arr[a+1]
	#print x
	val=arr[a]
	if(val==0 or x==1):
		print "Yes"
		continue
	if(val==1):
		if(val%x==0):
			print "Yes"
		else:
			print "No"
		continue
	calc=val
	calc%=x
	calc1=64
	#calc2=math.log10(val)
	#calc1/=calc2
	calc1=int(calc1)
	calc1+=2
	flagit=0
	for i in range(1,calc1):
		if(calc==0):
			flagit=1
			break
		calc*=val
		calc%=x
	if(flagit==0):
		print "No"
		continue
	else:
		if(a==b):
			if(val%x==0):
				print "Yes"
			else:
				print "No"
			continue
		limitit=b
		if(a+7<limitit):
			limitit=a+7
		flagit=0
		for i in range(a+1,limitit):
			if(arr[i]==1 or arr[i]==0):
				flagit=1
				limitit=i
				break
		x1=arr[limitit]
		#print limitit
		flagit=0
		for i in range(limitit-1,a,-1):
			ans=powerit(arr[i],x1,calc1,1)
			if(ans>=calc1):
				flagit=1
				break
			x1=ans
		if(flagit==1):
			print "Yes"
			continue
		ans=powerit(arr[a],x1,x,0)
		#print ans,arr[a]
		if(ans==-1 or flagit==1):
			print "Yes"
		else:
			print "No"
