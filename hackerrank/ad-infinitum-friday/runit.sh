for i in {1..20000}
	do
		python testgenerator.py > in2
		g++ brute_force.cpp
		./a.out < in2 > actual
		g++ wet_shark.cpp
		./a.out < in2 > akash
		if diff akash actual > /dev/null ; then
			echo same
		else 
			echo different
			exit 0
		fi
	done
