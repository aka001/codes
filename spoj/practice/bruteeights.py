for i in range(1,50000):
	calc=i*i*i
	calc%=1000
	if(calc==888):
		print i
