#include<bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(i=0; i<n; i++)
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
using namespace std;
int dp[1<<21], vit[1<<21];
class OrderOfOperationsDiv2 {
	public:
	int minTime(vector <string> s) {
		int n,m,n1,m1,i,j,k,calc,cnt,val;
		memset(dp, mod, sizeof(dp));
		dp[0]=vit[0]=0;
		n=s.size(); m=s[0].size();
		n1=1<<n; m1=1<<m;
		rep(i,n1)
		{
			rep(j,n)
			{
				if((i&(1<<j))==0)
				{
					calc=vit[i];
					cnt=0;
					rep(k,m)
					{
						if(s[j][k]=='1' && (calc&(1<<k))==0)
						{
							calc=calc|(1<<k);
							cnt++;
						}
					}
					val = (i|(1<<j));
					dp[val]=min(dp[val], dp[i]+cnt*cnt);
					//trace6(i, j, val, cnt, dp[i], dp[val]);
					vit[val]=calc;
					calc=vit[i];
				}
			}
		}
		return dp[n1-1];
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
		cout << "Testing OrderOfOperationsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1442856773;
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
		OrderOfOperationsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {
				              "111",
				              "001",
				              "010"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			/*case 1:
			{
				string s[] = {
				              "11101",
				              "00111",
				              "10101",
				              "00000",
				              "11000"
				             };
				_expected = 9;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 2:
			{
				string s[] = {
				               "11111111111111111111"
				             };
				_expected = 400;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 3:
			{
				string s[] = {
				               "1000",
				               "1100",
				               "1110"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 4:
			{
				string s[] = {
				               "111",
				               "111",
				               "110",
				               "100"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
