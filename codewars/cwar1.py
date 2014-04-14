import math
t=input()
for i in range(0,t):
	at=raw_input().split()
	n=int(at[0])
	k=int(at[1])
	ans=math.ceil(n/2)
	if(k>ans):
		k=n-k+1
	k-=1
	if(k==0):
		print n
		continue
	else:
	 	n-=k
		x=1
		cnt=1
		c=0
		calc=1
		c%=1000000007
		for j in range(0,k+1):
			calc=(calc*(n+x-1))/x
			if(k!=cnt):
				c+=calc
				c%=1000000007
			cnt+=1
			x+=1
		print c+1
