#include<bits/stdc++.h>
using namespace std;
class RandomPancakeStackDiv2 {
	public:
	double expectedDeliciousness(vector <int> d) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing RandomPancakeStackDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431978792;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomPancakeStackDiv2 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {1,1,1};
				_expected = 1.6666666666666667;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {10,20};
				_expected = 20.0;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {3,6,10,9,2};
				_expected = 9.891666666666667;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {10,9,8,7,6,5,4,3,2,1};
				_expected = 10.999999724426809;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 7.901100088183421;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 5:
			{
				int d[] = {1,1,1,1,1,1,1,1,1,1};
				_expected = 1.7182818011463845;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 6:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.expectedDeliciousness(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
