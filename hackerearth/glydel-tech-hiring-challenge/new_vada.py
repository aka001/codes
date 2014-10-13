listit=[]
n=input()
dicit={}
for i in range(0,n):
	x=raw_input().split()[0]
	if x not in dicit.keys():
		listit.append(x)
		dicit[x]=1
listit.sort()
sz=len(listit)
print sz
for i in listit:
	print i
