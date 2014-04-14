def power(x,y):
	s=x
	ans=1
	for j in range(0,100):
		if y&01==1:
			ans=ans*s
			if ans>1000000007:
				ans%=1000000007
		s=s*s;
		if s>1000000007:
			s%=1000000007
		y>>=1
		if y==0:
			break
	return ans
t=input()
for i in range(0,t):
	x=input()
	num=1
	s=0
	for j in range(1,100):
		if x==0:
			break
		num=num*10+x%2
		x>>=1
	for j in range(1,100):
		if num==0:
			break
		x=num%10
		s=s*10+x
		num/=10
	s/=10
	s%=1000000006
	ans=power(4,s)
	print ans
