ans=[]
for i in range(1,704978):
	val=i**(0.33333)
	val=int(val)
	cnt=0
	for j in range(1,val+1):
		calc=i-j*j*j
		calc1=calc**0.33333
		calc1+=0.501
		calc1=int(calc1)
		if(calc1*calc1*calc1==calc):
			cnt+=1
		if(cnt>=2):
			print i
			ans.append(i)
			break;
