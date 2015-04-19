for i in {1..20000}
	do
		python testgenerator.py > input
		g++ 3.cpp
		./a.out < input > akash
		g++ test.cpp
		./a.out < input > output
		if diff akash output > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
