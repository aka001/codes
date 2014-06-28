a=[]
inp=raw_input().split()
n=int(inp[0])
k=int(inp[1])
a.append(1)
a.append(1)
calc=1
for i in range(2,101):
	calc=calc*i
	a.append(calc)
sumit=1
for i in range(1,n+1):
	sumit+=a[i]**k
while sumit!=0:
	calc=sumit%10
	if(calc!=0):
		print calc
		break
	sumit/=10
