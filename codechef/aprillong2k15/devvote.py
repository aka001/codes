den=[]
num=[]
for i in range(0,19):
	num.append(0)
	den.append(0)
den[1]=1
den[2]=2
den[3]=12
den[4]=60
den[5]=240
den[6]=1020
den[7]=4020
den[8]=16380
den[9]=65280
den[10]=262080
den[11]=1047540
den[12]=4194300
den[13]=16772880
den[14]=67108860
den[15]=268419060
den[16]=1073740740
den[17]=4294901760
den[18]=17179869180

num[1]=1
num[2]=4
num[3]=24
num[4]=144
num[5]=864
num[6]=5184
num[7]=31104
num[8]=186624
num[9]=1119744
num[10]=6718464
num[11]=40310784
num[12]=241864704
num[13]=1451188224
num[14]=8707129344
num[15]=52242776064
num[16]=313456656384
num[17]=1880739938304
num[18]=11284439629824

t=input()
for i in range(0,t):
	n=input()
	calc=num[n]/(den[n]*1.000000)
	print("%.6f" % round(calc,6))
