def findclosest(n):
	val=1
	while(val<=n):
		val=val*2
	val/=2
	return val
t=input()
for i in range(0,t):
	n=input()
	cnt=0
	while(n!=1):
		cnt+=1
		if((n&(n-1))==0):
			n/=2
		else:
			val=findclosest(n)
			n-=val
	if(cnt%2==1):
		print "Louise"
	else:
		print "Richard"
