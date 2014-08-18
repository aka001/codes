for i in {1..20000}
	do
		python testit.py > in2
		g++ new4.cpp
		./a.out < in2 > akash
		python bruteforce.py < in2 > output
		if diff akash output > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
