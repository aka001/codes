for i in {1..20000}
	do
		python testgenerator.py > in2
		g++ sublcm.cpp
		./a.out < in2 > akash
		g++ origsublcm.cpp
		./a.out < in2 > output
		if diff akash output > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
