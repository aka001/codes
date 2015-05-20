#include<bits/stdc++.h>
using namespace std;
class RabbitStepping {
	public:
	double getExpected(string field, int r) {
		
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
		cout << "Testing RabbitStepping (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431545097;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RabbitStepping _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field = "WRBRW";
				int r = 4;
				_expected = 0.8;
				_received = _obj.getExpected(field, r); break;
			}
			case 1:
			{
				string field = "WWB";
				int r = 2;
				_expected = 1.3333333333333333;
				_received = _obj.getExpected(field, r); break;
			}
			case 2:
			{
				string field = "WW";
				int r = 1;
				_expected = 1.0;
				_received = _obj.getExpected(field, r); break;
			}
			case 3:
			{
				string field = "BBBBBBBBBB";
				int r = 4;
				_expected = 0.9523809523809523;
				_received = _obj.getExpected(field, r); break;
			}
			case 4:
			{
				string field = "RRBRRWRRBRRW";
				int r = 8;
				_expected = 0.9696969696969697;
				_received = _obj.getExpected(field, r); break;
			}
			/*case 5:
			{
				string field = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(field, r); break;
			}*/
			/*case 6:
			{
				string field = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(field, r); break;
			}*/
			/*case 7:
			{
				string field = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(field, r); break;
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
