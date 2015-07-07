a = raw_input().split()
ans = 1<<32
ans -= 1
for i in a:
	i1 = int(i)
	ans = ans & i1
print ans
