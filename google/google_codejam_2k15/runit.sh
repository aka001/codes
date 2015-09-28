for i in {1..20000}
	do
		python testgenerator.py
		g++ akashsolution.cpp
		./a.out < in2 > akash
		g++ shikhersolution.cpp -std=c++11
		./a.out < in2 > output
		if diff akash output > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
