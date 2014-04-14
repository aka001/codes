cnt=1
for i in range(0,10000000):
	x=i**0.2
	if(x==int(x)):
		y=i**(1/3)
		if(y==int(y)):
			z=i**0.5
			if(z==int(z)):
				cnt+=1
print cnt
