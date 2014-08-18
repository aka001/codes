for i in {1..2000}
	do
		python testgenerator.py > in2
		g++ prgift.cpp
		./a.out < in2 > kotak
		g++ newprgift.cpp
		./a.out < in2 > akash
		if diff akash kotak > /dev/null ; then
			echo same
		else
			echo different
			exit 0
		fi
	done
