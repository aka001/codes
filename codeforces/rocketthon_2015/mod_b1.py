import itertools
inp=raw_input().split()
n=int(inp[0])
m=int(inp[1])
val=range(1,n+1)
ans=-100000
for p in itertools.permutations(val):
	calc=0
	for i in range(n):
		minit=1000000
		for j in range(i,n):
			minit=min(minit,p[j])
			calc+=minit
	ans=max(ans,calc)
	break
cnt=0
for p in itertools.permutations(val):
	calc=0
	for i in range(n):
		minit=1000000
		for j in range(i,n):
			minit=min(minit,p[j])
			calc+=minit
	if(calc==ans):
		print p
		cnt+=1
	'''if(cnt==m):
		for i in range(n):
			if(i==n-1):
				print p[i]
			else:
				print p[i],'''
