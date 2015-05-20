#include<bits/stdc++.h>
using namespace std;
class CorruptedMessage {
	public:
		string reconstructMessage(string s, int k) 
		{
			int i,sz,freq[256],cnt=0,calc;
			for(i=0;i<256;i++)
				freq[i]=0;
			sz=s.size();
			for(i=0;i<sz;i++)
			{
				freq[s[i]-'a']++;
			}
			for(i=0;i<26;i++)
			{
				if(freq[i]!=0)
					cnt++;
			}
			calc=sz-k;
			for(i=0;i<26;i++)
			{
				if(freq[i]==calc)
					break;
			}
			char ch='a'+i;
			string ans="";
			for(i=0;i<sz;i++)
				ans+=ch;
			return ans;
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
		cout << "Testing CorruptedMessage (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431978094;
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
		CorruptedMessage _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
				{
					string s = "hello";
					int k = 3;
					_expected = "lllll";
					_received = _obj.reconstructMessage(s, k); break;
				}
			case 1:
				{
					string s = "abc";
					int k = 3;
					_expected = "ddd";
					_received = _obj.reconstructMessage(s, k); break;
				}
			case 2:
				{
					string s = "wwwwwwwwwwwwwwwwww";
					int k = 0;
					_expected = "wwwwwwwwwwwwwwwwww";
					_received = _obj.reconstructMessage(s, k); break;
				}
			case 3:
				{
					string s = "ababba";
					int k = 3;
					_expected = "aaaaaa";
					_received = _obj.reconstructMessage(s, k); break;
				}
			case 4:
				{
					string s = "zoztxtoxytyt";
					int k = 10;
					_expected = "oooooooooooo";
					_received = _obj.reconstructMessage(s, k); break;
				}
			case 5:
				{
					string s = "jlmnmiunaxzywed";
					int k = 13;
					_expected = "mmmmmmmmmmmmmmm";
					_received = _obj.reconstructMessage(s, k); break;
				}
				/*case 6:
				  {
				  string s = ;
				  int k = ;
				  _expected = ;
				  _received = _obj.reconstructMessage(s, k); break;
				  }*/
				/*case 7:
				  {
				  string s = ;
				  int k = ;
				  _expected = ;
				  _received = _obj.reconstructMessage(s, k); break;
				  }*/
				/*case 8:
				  {
				  string s = ;
				  int k = ;
				  _expected = ;
				  _received = _obj.reconstructMessage(s, k); break;
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
