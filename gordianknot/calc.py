def check(n):
	n1=n
	flag=0
	x=n%10
	n/=10
	cnt=1
	if x==0:
		return cnt
	while n!=0:
		y=n%10
		if x!=y or y==0:
			break
		cnt+=1
		n/=10
	return cnt

a=[]
a.append(4)
maxit=-1
for i in range(3,10000):
	calc=i**2
	calc1=check(calc)
	if(calc1>maxit):
		maxit=calc1
		max1=calc
print maxit
print max1
print check(max1)
