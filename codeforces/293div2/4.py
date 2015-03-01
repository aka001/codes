MAX=2003
triangle = [[0 for x in range(MAX+1)] for x in range(MAX+1)] 
def makeTriangle():
	triangle[0][0] = 1
	for i in range(1,MAX-1):
		triangle[i][0] = 1
		for j in range(1,i+1):
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
'''for i in range(0,MAX+1):
	temp=[]
	for j in range(0,MAX+1):
		temp.append(0)
	triangle.append(temp)
	del temp'''
makeTriangle()
tot=raw_input().split()
n=int(tot[0])
p=float(tot[1])
t=int(tot[2])
t1=[]
t2=[]
ans=0
for i in range(1,2009):
	t1.append(0)
	t2.append(0)
for i in range(1,2008):
	if(i==1):
		t1[i]=p
		t2[i]=1-p
	else:
		t1[i]=p*t1[i-1]
		t2[i]=(1-p)*t2[i-1]
t1[0]=t2[0]=1
for i in range(1,n+1):
	calc=p
	for j in range(t-1,-1,-1):
		c1=i-1
		c2=j-c1
		if(c1<0 or c2<0):
			continue
		calc=p*t1[c1]*t2[c2]*triangle[c1+c2][c1]
		ans+=calc
print ans
