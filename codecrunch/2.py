import sys
a={}
a.append("-----")
a.append(".----")
a.append("..---")
a.append("...--")
a.append("....-")
a.append(".....")
a.append("-....")
a.append("--...")
a.append("---..")
a.append("----.")
print len(a)
print a[9]
t=input()
for i in range(0,t):
	a=raw_input().split("\n")
	for j in a[0]:
		k=int(j)
#a[int(j)],
	print
