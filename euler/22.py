inp=raw_input().split(',')
print len(inp)
inp.sort()
ans=0
cnt=0
for i in inp:
	cnt+=1
	string=i
	ans1=0
	for s in string:
		store=ord(s)
		if(store>=65 and store<=90):
			store-=64
		elif(store>=97 and store<=122):
			store-=96
		if(store>=1 and store<=26):
			ans1+=store
	ans+=ans1*cnt
print ans
