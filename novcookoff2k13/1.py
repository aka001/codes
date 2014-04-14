def betterguess(x,g):
	return ((g+x/g)/2)
def closeenough(a,b):
	x=a-b
	if x<0:
		x*=-1
	x/=b
	if x<0.001:
		return True
	else:
		return False
def test(x,g):
	if closeenough(x/g,g):
		return g
	else:
		return test(x,betterguess(x,g))
def isperfect(x):
	s=test(x,4)
	s=int(s)
	if s**2==x:
		return True
	else:
		return False
def isfibo(n):
#print 5*n*n+4
#	print 5*n*n-4
	return isperfect(5*n*n+4) or isperfect(5*n*n-4)
t=input()
for i in range(0,t):
	n=input()
	print test(n,1)
	if n==0:
		print "YES"
		continue
	if isfibo(n):
		print "YES"
	else:
		print "NO"
