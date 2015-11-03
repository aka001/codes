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

class ChemicalMixing {
	public:
	double closestBlend(vector <int> volume, vector <int> solute, int minVolume, double desiredStrength) {
		
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
		cout << "Testing ChemicalMixing (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444405184;
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
		ChemicalMixing _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int volume[] = {10, 10};
				int solute[] = {1, 4};
				int minVolume = 5;
				double desiredStrength = 0.20;
				_expected = 0.04999999999999999;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}
			case 1:
			{
				int volume[] = {10, 10, 10, 10};
				int solute[] = { 5,  5,  5,  0} ;
				int minVolume = 35;
				double desiredStrength = 0.5;
				_expected = 0.125;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}
			case 2:
			{
				int volume[] = {20, 20, 20};
				int solute[] = {15, 15, 0};
				int minVolume = 40;
				double desiredStrength = 0.5;
				_expected = 0.0;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}
			case 3:
			{
				int volume[] = {50, 50, 50, 50};
				int solute[] = {12, 4, 20, 0};
				int minVolume = 100;
				double desiredStrength = 0.5;
				_expected = 0.18;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}
			/*case 4:
			{
				int volume[] = ;
				int solute[] = ;
				int minVolume = ;
				double desiredStrength = ;
				_expected = ;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}*/
			/*case 5:
			{
				int volume[] = ;
				int solute[] = ;
				int minVolume = ;
				double desiredStrength = ;
				_expected = ;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}*/
			/*case 6:
			{
				int volume[] = ;
				int solute[] = ;
				int minVolume = ;
				double desiredStrength = ;
				_expected = ;
				_received = _obj.closestBlend(vector <int>(volume, volume+sizeof(volume)/sizeof(int)), vector <int>(solute, solute+sizeof(solute)/sizeof(int)), minVolume, desiredStrength); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
