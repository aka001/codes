#include<bits/stdc++.h>
using namespace std;
class ProblemSetsEasy {
	public:
	int maxSets(int E, int EM, int M, int MH, int H) {
		
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
		cout << "Testing ProblemSetsEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431978076;
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
		ProblemSetsEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int E = 2;
				int EM = 2;
				int M = 1;
				int MH = 2;
				int H = 2;
				_expected = 3;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 1:
			{
				int E = 100;
				int EM = 100;
				int M = 100;
				int MH = 0;
				int H = 0;
				_expected = 0;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 2:
			{
				int E = 657;
				int EM = 657;
				int M = 657;
				int MH = 657;
				int H = 657;
				_expected = 1095;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 3:
			{
				int E = 1;
				int EM = 2;
				int M = 3;
				int MH = 4;
				int H = 5;
				_expected = 3;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 4:
			{
				int E = 100000;
				int EM = 100000;
				int M = 100000;
				int MH = 100000;
				int H = 100000;
				_expected = 166666;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			/*case 5:
			{
				int E = ;
				int EM = ;
				int M = ;
				int MH = ;
				int H = ;
				_expected = ;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}*/
			/*case 6:
			{
				int E = ;
				int EM = ;
				int M = ;
				int MH = ;
				int H = ;
				_expected = ;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}*/
			/*case 7:
			{
				int E = ;
				int EM = ;
				int M = ;
				int MH = ;
				int H = ;
				_expected = ;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
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
