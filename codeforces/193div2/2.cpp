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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
struct cmp
{
	bool operator()(pair<ll, ll> a, pair<ll, ll> b)
	{
		if(a.F==b.F)
			return a.S>b.S;
		return a.F<=b.F;
	}
};
ll arr[MAX],trck[MAX];
set<pair<ll, ll>, cmp > stit;
//This is O(nlogn) solution. However, O(n) solution exists.
int main()
{
	ll n,k,val,sum=0,i,mx=-1,l=-1,h=-1;
	sl(n);
	sl(k);
	rep(i,n)
		sl(arr[i]);
	rep(i,k)
	{
		sum+=arr[i];
	}
	rep(i,n-k+1)
	{
		trck[i]=sum;
		if(i!=n-k)
			sum=sum-arr[i]+arr[i+k];
	}
	val=k;
	FOR(i,val,n-k+1)
	{
		stit.insert(mp(trck[i],i));
		//trace2(trck[i],i);
	}
	pair<ll,ll> calc;
	rep(i,n-2*k+1)
	{
		if(!stit.empty())
			calc=*stit.rbegin();
		val=trck[i]+calc.F;
		//trace4(i,val,calc.F,calc.S);
		if(val>mx)
		{
			l=i;
			h=calc.S;
			mx=val;
		}
		//if(stit.find(mp(trck[i+k],i+k))
		stit.erase(stit.find(mp(trck[i+k],i+k)));
	}
	printf("%lld %lld\n",l+1,h+1);
	return 0;
}













