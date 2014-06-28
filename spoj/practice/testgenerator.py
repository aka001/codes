import random
import string
t=20
print t
for i in range(0,t):
	length=random.randint(1,6)
	strit=''
	for j in range(0,length):
		char=random.choice(string.letters)
		strit+=char
	print strit
