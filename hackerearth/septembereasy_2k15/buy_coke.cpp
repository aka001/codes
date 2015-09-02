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
#define mod (int)(1e9 + 7)
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
int tot, dp[151][151][151],c;
int compute(int coke, int n5, int n10)
{
	int &ret = dp[coke][n5][n10];
	if(ret!=-1)
		return ret;
	else if(coke==c)
		return 0;
	else
	{
		ret=mod;
		int n1=tot-8*coke-n5*5-n10*10;
		if(n10>=1)
			ret=min(ret, 1+compute(coke+1, n5, n10-1));
		if(n5>=2)
			ret=min(ret, 2+compute(coke+1, n5-2, n10));
		if(n5>=1 && n1>=3)
			ret=min(ret, 4+compute(coke+1, n5-1, n10));
		if(n10>=1 && n1>=3)
			ret=min(ret, 4+compute(coke+1, n5+1, n10-1));
		if(n1>=8)
			ret=min(ret, 8+compute(coke+1, n5, n10));
		return ret;
	}
}
int main()
{
	int t,n1,n5,n10,ans;
	si(t);
	while(t--)
	{
		si(c); si(n1); si(n5); si(n10);
		tot=n1+5*n5+10*n10;
		if(tot<8*c)
		{
			pin(-1);
			continue;
		}
		memset(dp, -1, sizeof(dp));
		ans = compute(0, n5, n10);
		pin(ans);
	}
	return 0;
}













