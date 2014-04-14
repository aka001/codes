a=100
s=1
sumit=0
for i in range(2,101):
	s*=i
while s!=0:
	sumit+=s%10
	s/=10
print sumit
