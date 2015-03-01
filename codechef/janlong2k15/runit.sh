for i in {1..20000}
	do
		python testgenerator.py > in4
		g++ qset.cpp
		./a.out < in4 > akash
		g++ brute.cpp
		./a.out < in4 > output
		if diff akash output > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
