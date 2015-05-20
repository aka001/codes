#include<bits/stdc++.h>
using namespace std;
class InfiniteString {
	public:
	string equal(string s, string t) {
		
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
		cout << "Testing InfiniteString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431978028;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		InfiniteString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				string t = "abab";
				_expected = "Equal";
				_received = _obj.equal(s, t); break;
			}
			case 1:
			{
				string s = "abc";
				string t = "bca";
				_expected = "Not equal";
				_received = _obj.equal(s, t); break;
			}
			case 2:
			{
				string s = "abab";
				string t = "aba";
				_expected = "Not equal";
				_received = _obj.equal(s, t); break;
			}
			case 3:
			{
				string s = "aaaaa";
				string t = "aaaaaa";
				_expected = "Equal";
				_received = _obj.equal(s, t); break;
			}
			case 4:
			{
				string s = "ababab";
				string t = "abab";
				_expected = "Equal";
				_received = _obj.equal(s, t); break;
			}
			case 5:
			{
				string s = "a";
				string t = "z";
				_expected = "Not equal";
				_received = _obj.equal(s, t); break;
			}
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.equal(s, t); break;
			}*/
			/*case 7:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.equal(s, t); break;
			}*/
			/*case 8:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.equal(s, t); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
