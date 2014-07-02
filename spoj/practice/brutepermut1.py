import itertools
import os
s=raw_input().split()[0]
a=list(itertools.permutations(s,len(s)))
os.system("g++ invcnt.cpp")
lenit=len(s)
dictit={}
calc=(lenit*(lenit-1))/2
for i in range(0,calc):
	dictit[i]=0
for i in a:
	x=i
	cnt=0
	for j in range(0,lenit):
		for k in range(j+1,lenit):
			if(i[j]>i[k]):
				cnt+=1
	if cnt not in dictit.keys():
		dictit[cnt]=1
	else:
		dictit[cnt]+=1
for key in dictit:
	print key,dictit[key]
