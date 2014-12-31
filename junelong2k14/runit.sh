for i in {1..2000}
	do
		python testgenerator.py
		./karan < in1 > output
		./a.out < in1 > my
		if diff my output > /dev/null ; then
			echo same
		else
			echo different
			exit 0
		fi
	done
