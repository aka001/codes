#include<bits/stdc++.h>
using namespace std;
class PublicTransit {
	public:
	int minimumLongestDistance(int R, int C) {
		
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
		cout << "Testing PublicTransit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431971383;
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
		PublicTransit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 4;
				int C = 1;
				_expected = 1;
				_received = _obj.minimumLongestDistance(R, C); break;
			}
			case 1:
			{
				int R = 2;
				int C = 2;
				_expected = 1;
				_received = _obj.minimumLongestDistance(R, C); break;
			}
			case 2:
			{
				int R = 5;
				int C = 3;
				_expected = 4;
				_received = _obj.minimumLongestDistance(R, C); break;
			}
			case 3:
			{
				int R = 8;
				int C = 2;
				_expected = 4;
				_received = _obj.minimumLongestDistance(R, C); break;
			}
			/*case 4:
			{
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.minimumLongestDistance(R, C); break;
			}*/
			/*case 5:
			{
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.minimumLongestDistance(R, C); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.minimumLongestDistance(R, C); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE