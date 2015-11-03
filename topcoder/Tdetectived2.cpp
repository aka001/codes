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

class Tdetectived2 {
	public:
	vector<int> dp;
	vector<vector<int> > mem;
	int susp[20];
	int reveal(vector <string> s) {
		int i,sz,ans=0,j;
		sz = s.size();
		rep(i,sz+2)
		{
			dp.pb(mod);
		}
		rep(i,sz)
		{
			susp[i] = (s[0][i] - '0');
		}
		rep(i,1<<sz)
		{
			vector<int> temp;
			rep(j,sz)
				temp.pb(-1);
			mem.pb(temp);
		}
		//fill(mem, false);
		compute(1, s, 0);
		FOR(i,1,sz)
		{
			ans+=i*dp[i];
		}
		return ans;
	}
	void compute(int mask, vector<string> s, int cnt)
	{
		int &ret = mem[mask][cnt];
		if(ret!=-1)
			return;
		int n = s.size(),high,mx,calc,i,j;
		high = 1<<n; high--;
		if(mask == high)
			return;
		mx = -mod;
		for(i=1; i<n; i++)
		{
			if((mask&(1<<i)) == 0)
				mx = max(mx, susp[i]);
		}
		int susp1[20];
		rep(i,n)
			susp1[i]= susp[i];
		for(i=1; i<n; i++)
		{
			if((mask&(1<<i)) == 0)
			{
				if(susp1[i]==mx)
				{
					dp[i] = min(dp[i], cnt+1);
					for(j=0; j<n; j++)
					{
						calc = s[i][j]-'0';
						susp[j] = max(susp[j], calc);
					}
					compute(mask|(1<<i), s, cnt+1);
					rep(j,n)
						susp[j] = susp1[j];
				}
			}
		}
		ret = 1;
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
		cout << "Testing Tdetectived2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1445390697;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Tdetectived2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"000","000","000"};
				_expected = 3;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 1:
			{
				string s[] = {"0224","2011","2104","4140"};
				_expected = 10;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 2:
			{
				string s[] = {"0886","8086","8801","6610"};
				_expected = 12;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 3:
			{
				string s[] = {"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"};
				_expected = 170;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 4:
			{
				string s[] = {"0313131","3030020","1301132","3010031","1010003","3233003","1021330"};
				_expected = 37;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			/*case 5:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.reveal(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
