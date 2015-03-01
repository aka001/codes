from math import factorial
inp=raw_input().split()
n=int(inp[0])
m=int(inp[1])
i=(m-1)
p=range(1,n+1)
ans=[]
cnt=n
for k in range(1,n+1):
	f=factorial(n-k)
	d=i/f
	ans.append(p[d])
	p.remove(p[d])
	i=i%f
	cnt-=1
lit=len(ans)
for k in range(0,lit):
	if(k==lit-1):
		print ans[k]
	else:
		print ans[k],
