import sys
def choose_iter(elements, length):
	for i in xrange(len(elements)):
		if length == 1:
			yield (elements[i],)
		else:
			for next in choose_iter(elements[i+1:len(elements)], length-1):
				yield (elements[i],) + next
def choose(l, k):	
	return list(choose_iter(l, k))
ar=[]
flag=0
for i in range(0,100000):
	ar=[]
	a=raw_input().split()
	k=int(a[0])
	if(k==0):
		break
	if flag!=0:
		print
	flag=1
	z=len(a)
	for i in range(1,z):
		ar.append(int(a[i]))

	br=list(choose_iter(ar,6))
	z=len(br)
	for j in range(0,z):
		z1=6
		p=br[j]
		for k in range(0,6):
			#sys.stdout.write(str(br[k]),end="")
			print p[k],
		print
	print
