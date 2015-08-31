#include<bits/stdc++.h>
using namespace std;
class LuckySum {
	public:
	long long construct(string note) {
		
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
		cout << "Testing LuckySum (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440894999;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LuckySum _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string note = "?";
				_expected = 8LL;
				_received = _obj.construct(note); break;
			}
			case 1:
			{
				string note = "?1";
				_expected = 11LL;
				_received = _obj.construct(note); break;
			}
			case 2:
			{
				string note = "4?8";
				_expected = 448LL;
				_received = _obj.construct(note); break;
			}
			case 3:
			{
				string note = "2??";
				_expected = -1LL;
				_received = _obj.construct(note); break;
			}
			case 4:
			{
				string note = "??????????????";
				_expected = 11888888888888LL;
				_received = _obj.construct(note); break;
			}
			/*case 5:
			{
				string note = ;
				_expected = LL;
				_received = _obj.construct(note); break;
			}*/
			/*case 6:
			{
				string note = ;
				_expected = LL;
				_received = _obj.construct(note); break;
			}*/
			/*case 7:
			{
				string note = ;
				_expected = LL;
				_received = _obj.construct(note); break;
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
