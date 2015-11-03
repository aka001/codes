/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define F first
#define S second
#define mod (ll)(1e9 + 7)
#define ll long long int
#define MAX 1000006
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

class BearPaints {
	public:
	long long maxArea(int W, int H, long long M) {
		ll ans = 0,i,calc,w=W, h=H;
		FOR(i,1,w+1)
		{
			calc = M/i;
//			if(calc>h)
//				calc=h;
			if(calc>=1 && calc<=h)
			{
				ans = max(ans, calc*i);
			}
		}
		FOR(i,1,h+1)
		{
			calc = M/i;
			if(calc>=1 && calc<=w)
			{
				ans = max(ans, calc*i);
			}
		}
		if(w*h<=M)
			ans = max(ans, w*h);
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
		cout << "Testing BearPaints (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444834802;
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
		BearPaints _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int W = 4;
				int H = 6;
				long long M = 14LL;
				_expected = 12LL;
				_received = _obj.maxArea(W, H, M); 
				trace1(_received);
				break;
			}
			case 1:
			{
				int W = 4;
				int H = 4;
				long long M = 10LL;
				_expected = 9LL;
				_received = _obj.maxArea(W, H, M); break;
			}
			case 2:
			{
				int W = 1000000;
				int H = 12345;
				long long M = 1000000000000LL;
				_expected = 12345000000LL;
				_received = _obj.maxArea(W, H, M); break;
			}
			case 3:
			{
				int W = 1000000;
				int H = 1000000;
				long long M = 720000000007LL;
				_expected = 720000000000LL;
				_received = _obj.maxArea(W, H, M); break;
			}
			case 4:
			{
				int W = 1000000;
				int H = 1000000;
				long long M = 999999999999LL;
				_expected = 999999000000LL;
				_received = _obj.maxArea(W, H, M); break;
			}
			/*case 5:
			{
				int W = ;
				int H = ;
				long long M = LL;
				_expected = LL;
				_received = _obj.maxArea(W, H, M); break;
			}*/
			/*case 6:
			{
				int W = ;
				int H = ;
				long long M = LL;
				_expected = LL;
				_received = _obj.maxArea(W, H, M); break;
			}*/
			/*case 7:
			{
				int W = ;
				int H = ;
				long long M = LL;
				_expected = LL;
				_received = _obj.maxArea(W, H, M); break;
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
