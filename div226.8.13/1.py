a=raw_input().split('+')
lst=[]
lst.append(0)
lst.append(0)
lst.append(0)
for i in range(0,len(a)):
	b=int(a[i])
	if(b==1):
		lst[0]+=1
	elif(b==2):
		lst[1]+=1
	elif(b==3):
		lst[2]+=1
s=""
#print lst[0]
#print lst[1]
#print lst[2]
for i in range(0,len(lst)):
	for j in range(0,lst[i]):
		if(i==0):
			s+="1"+"+"
		if(i==1):
			s+="2"+"+"
		if(i==2):
			s+="3"+"+"
print s[:len(s)-1]		
