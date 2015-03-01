import random
t=input()
for i in range(0,t):
	a=input()
	b=a
	k=input()
	val=raw_input().split()
	for j in range(0,k):
		val[j]=int(val[j])
	fin=1000000
	stit=str(a)
	arr=[]
	a=b
	while(a!=0):
		arr.append(a%10)
		a/=10
	sz=len(arr)
	for j in range(0,3):
		for l in range(0,sz):
			calc=random.randint(0,sz-l-1)
			temp=arr[calc]
			arr[calc]=arr[sz-l-1]
			arr[sz-l-1]=temp
		sit=0
		for l in range(0,k):
			cit=0
			for m in range(0,sz):
				cit=(cit*10+arr[m])
				if(cit>=val[l]):
					cit%=val[l]
			sit+=cit
		if sit<fin:
		  	fin=sit
			stit=""
			for i in range(0,sz):
				stit+=str(arr[i])
#print sit,stit
			if(sit==0):
				break
	print stit

