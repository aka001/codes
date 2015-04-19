import random
t=100
name='in2'
file=open(name, 'w')
file.write(str(t)+"\n")
len_s=1000
for i in range(0,t):
	n=random.randint(1,6)
	file.write(str(n)+"\n")
	for j in range(0,n):
		val=random.randint(1,9)
		file.write(str(val))
		if(j!=n-1):
			file.write(" ")
		else:
			file.write("\n")
