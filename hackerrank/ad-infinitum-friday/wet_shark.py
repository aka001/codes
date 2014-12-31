t=input()
cit=42
mod=1000000007
for i in range(0,t):
	s=input()
	ans=s*2
	low=0
	high=ans
	while(s>0):
		num=(high-low)/cit
		s=num
		low=high
		high+=num*2
	high%=mod
	print high
