def make_num_new(l,tot):
	num=10**1001
	flag=0
	vis=[]
	for i in range(0,tot):
		vis.append(0)
#print l
	while(1):
		fin=""
		flag=0
		jit=-1
		for j in range(0,lit):
			if l[j]==0 and vis[j]==0 and flag==0:
				jit=j
				flag=1
			if flag==1:
				fin+=str(l[j])
		#print jit
		vis[jit]=1
		if(flag==0):
			break
		for j in range(0,jit):
			fin+=str(l[j])
		s=int(fin)
		if s<num:
		 	ans=fin
			num=s
	return ans
def make_num(l,tot):
	num=10**1001
	flag=0
	vis=[]
	for i in range(0,tot):
		vis.append(0)
#print l
	while(1):
		fin=""
		flag=0
		jit=-1
		for j in range(0,lit):
			if l[j]==0 and vis[j]==0 and flag==0:
				jit=j
				flag=1
			if flag==1:
				fin+=str(l[j])
		vis[jit]=1
		if(flag==0):
			break
		for j in range(0,jit):
			fin+=str(l[j])
		s=int(fin)
		if s<num:
			num=s
	return num
garb=input()
l=[]
n=raw_input().split()[0]
minit=10**1001
for i in n:
	l.append(int(i))
lit=len(l)
#print lit
ans=0
ot=[]
for i in range(0,13):
	ot.append(0)
p=[]
for i in range(0,lit):
	p.append(0)
for i in range(0,lit):
	if(ot[l[i]]==1):
		continue
	for j in range(0,lit):
		p[j]=l[j]
	cnt=10-l[i]
	ot[l[i]]=1
	for j in range(0,lit):
		l[j]+=cnt
		l[j]%=10
	val=make_num(l,lit)
	for j in range(0,lit):
		l[j]=p[j]
#print i,val
	if(val<minit):
		ans=i
		minit=val
cnt=10-l[ans]
for j in range(0,lit):
	l[j]+=cnt
	l[j]%=10
print make_num_new(l,lit)
'''flag=0
fin=""
for j in range(0,lit):
	if l[j]==0:
		flag=1
	if flag==1:
		fin+=str(l[j])
flag=0
for j in range(0,lit):
	if(l[j]==0):
		flag=1
	if flag==0:
		fin+=str(l[j])
print fin'''
