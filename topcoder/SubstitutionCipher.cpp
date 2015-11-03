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

class SubstitutionCipher {
	public:
	string decode(string a, string b, string y) {
		int freq[27];
		fill(freq, -1);
		int i,sz,calc,cnt;
		sz=a.size();
		rep(i,sz)
			freq[b[i]-'A'] = a[i]-'A';
		cnt=0;
		rep(i,26)
		{
			if(freq[i]==-1)
				cnt++;
		}
		if(cnt==1)
		{
			calc = 0;
			rep(i,26)
			{
				if(freq[i]!=-1)
					calc+=freq[i];
			}
			calc = 325 - calc;
			rep(i,26)
				if(freq[i]==-1)
					freq[i]=calc;
		}
		sz = y.size();
		for(i=0; i<sz; i++)
		{
			calc = y[i] - 'A';
			if(freq[calc]==-1)
			{
//				trace2(i,"HIE");
				return "";
			}
			calc = freq[calc];
			y[i] = calc + 'A';
		}
		return y;
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
		cout << "Testing SubstitutionCipher (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1445389522;
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
		SubstitutionCipher _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string a = "CAT";
				string b = "DOG";
				string y = "GOD";
				_expected = "TAC";
				_received = _obj.decode(a, b, y); break;
			}
			case 1:
			{
				string a = "BANANA";
				string b = "METETE";
				string y = "TEMP";
				_expected = "";
				_received = _obj.decode(a, b, y); break;
			}
			case 2:
			{
				string a = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG";
				string b = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH";
				string y = "DIDYOUNOTICESKIPPEDLETTER";
				_expected = "CHCXNTMNSHBDRJHOODCKDSSDQ";
				_received = _obj.decode(a, b, y); break;
			}
			/*case 3:
			{
				string a = ;
				string b = ;
				string y = ;
				_expected = ;
				_received = _obj.decode(a, b, y); break;
			}*/
			/*case 4:
			{
				string a = ;
				string b = ;
				string y = ;
				_expected = ;
				_received = _obj.decode(a, b, y); break;
			}*/
			/*case 5:
			{
				string a = ;
				string b = ;
				string y = ;
				_expected = ;
				_received = _obj.decode(a, b, y); break;
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
