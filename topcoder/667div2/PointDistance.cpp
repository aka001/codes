#include<bits/stdc++.h>
using namespace std;
class PointDistance {
	public:
	vector <int> findPoint(int x1, int y1, int x2, int y2) {
		int i=-100, j=-100,v1,v2,c1,c2;
		vector<int> ans;
		for(i=-100;i<=100;i++)
		{
			for(j=-100;j<=100;j++)
			{
				c1=abs(x1-i);
				c2=abs(y1-j);
				v1=c1*c1+c2*c2;
				c1=abs(x2-i);
				c2=abs(y2-j);
				v2=c1*c1+c2*c2;
				//printf("%d %d\n",i,j);
				if(v1>v2)
				{
					ans.push_back(i); ans.push_back(j);
					return ans;
				}
			}
		}
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
		cout << "Testing PointDistance (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1441983709;
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
		PointDistance _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = -1;
				int y1 = 0;
				int x2 = 1;
				int y2 = 0;
				int __expected[] = {8, 48 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			case 1:
			{
				int x1 = 1;
				int y1 = 1;
				int x2 = -1;
				int y2 = -1;
				int __expected[] = {25, -63 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			case 2:
			{
				int x1 = 0;
				int y1 = 1;
				int x2 = 2;
				int y2 = 3;
				int __expected[] = {41, 65 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			case 3:
			{
				int x1 = 5;
				int y1 = -4;
				int x2 = -2;
				int y2 = 5;
				int __expected[] = {68, 70 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			case 4:
			{
				int x1 = -50;
				int y1 = -50;
				int x2 = 50;
				int y2 = -50;
				int __expected[] = {67, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			case 5:
			{
				int x1 = -50;
				int y1 = 50;
				int x2 = -49;
				int y2 = 49;
				int __expected[] = {73, -25 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}
			/*case 6:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}*/
			/*case 7:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
			}*/
			/*case 8:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPoint(x1, y1, x2, y2); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
