t=input()
for i in range(0,t):
	n=input()
	ans=32
	appit=[]
	for i in range(0,n):
		temp=[]
		for j in range(0,33):
			temp.append(0)
		appit.append(temp)
	for j in range(0,n):
		val=raw_input().split('.')
		cnt=0
		for k in range(0,3):
			calc=int(val[k])
			cnt=8*(k+1)-1
			while(calc!=0):
				appit[j][cnt]=calc%2
				calc/=2
				cnt-=1
	flag=1
	ans=0
	for j in range(0,32):
		for k in range(0,n-1):
			if(appit[k][j]!=appit[k+1][j]):
				flag=0
				break
		if(flag==0):
			break
		ans+=1
	git=[]
	for j in range(0,32):
		calc=j%8
		calc=8-calc-1
		calc=2**calc
		git.append(calc)
	val=0
	final=[]
	for j in range(0,32):
		if(j>=ans):
			val+=0
		else:
			val+=git[j]*appit[0][j]
		if j%8==7:
			final.append(val)
			val=0
	ait=ans
	ans/=8
	ansit=""
	for j in range(0,4):
		if(j!=3):
			ansit+=str(final[j])+"."
		else:
			ansit+=str(final[j])+"/"
	ansit+=str(ait)
	print ansit
