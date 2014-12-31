def modpow(a,n,temp):
	res=1
	y=a
	while(n>0):
		if(n%2==1):
			res=(res*y)%temp
		y=(y*y)%temp
		n/=2
	return res%temp
inp=raw_input().split()
a=int(inp[0])
b=int(inp[1])
calc=2**a
ans=modpow(2,calc,b)
print ans

