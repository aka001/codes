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
int compute(int val)
{
	int i,ans=0,calc;
	FOR(i,1,val)
	{
		calc=__gcd(i, val);
		if(calc==1)
			ans++;
	}
	//trace2(val, ans);
	if(val%ans==0)
	{
	//	trace2(val,ans);
		return 1;
	}
	return 0;
}
set<ll> sit,fin;
vector<ll> vec,nit;
int main()
{
	ll i,val,calc,sz,mit=1,cnt=0;
	rep(i,18)
		mit*=10;
	val=2;
	while(val<=mit && val>=0)
	{
		sit.insert(val);
		//trace1(val);
		val*=3;
	}
	while(!(sit.empty()))
	{
		val=*sit.begin();
		sit.erase(sit.begin());
		while(val<=mit && val>0)
		{
			fin.insert(val);
			val*=2;
		}
	}
	sz=fin.size();
	//trace1(sz);
	while(!(fin.empty()))
	{
		vec.pb(*fin.begin());
		fin.erase(fin.begin());
	}
	vec.pb(1);
	sz=vec.size();
	sort(ALL(vec));
	ll t,l,r,ans=0;
	sl(t);
	while(t--)
	{
		sl(l);
		sl(r);
		ans=0;
		rep(i,sz)
		{
			if(vec[i]>=l && vec[i]<=r)
				ans++;
		}
		pln(ans);
	}
	return 0;
}













