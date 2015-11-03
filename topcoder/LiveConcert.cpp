#include<bits/stdc++.h>
using namespace std;
class LiveConcert {
	public:
	int maxHappiness(vector <int> h, vector <string> s) {
		set<string> sit;
		int i,sz,n,ans=0;
		sz=s.size();
		for(i=0; i<sz; i++)
			sit.insert(s[i]);
		sz=sit.size();
		sort(h.begin(), h.end());
		n=h.size();
		n--;
		while(sz--)
		{
			ans+=h[n];
			n--;
			if(n==-1)
				break;
		}
		for(i=n-1; i>=0 && sz>=0; i--, sz--)
		{
			ans+=h[i];
		}
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
		cout << "Testing LiveConcert (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1443438005;
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
		LiveConcert _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int h[] = {10,5,6,7,1,2};
				string s[] = {"ciel","bessie","john","bessie","bessie","john"};
				_expected = 23;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 1:
			{
				int h[] = {3,3,4,3,3};
				string s[] = {"a","a","a","a","a"};
				_expected = 4;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 2:
			{
				int h[] = {1,2,3,4,5,6,7,8,9,10,100};
				string s[] = {"a","b","c","d","e","e","d","c","b","a","abcde"};
				_expected = 140;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 3:
			{
				int h[] = {100};
				string s[] = {"oyusop"};
				_expected = 100;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 4:
			{
				int h[] = {100,100,100,100,100,100,100,100,100,100,100,100,100};
				string s[] = {"haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko"};
				_expected = 1300;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			/*case 5:
			{
				int h[] = ;
				string s[] = ;
				_expected = ;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int h[] = ;
				string s[] = ;
				_expected = ;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int h[] = ;
				string s[] = ;
				_expected = ;
				_received = _obj.maxHappiness(vector <int>(h, h+sizeof(h)/sizeof(int)), vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
