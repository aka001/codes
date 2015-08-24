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
vector<pair<ll,ll> > query;
vector<ll> arr;
ll lower_bound(ll val)
{
	int l=0, h=arr.size()-1,mid,sz=arr.size();
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[mid]<=val && (mid==sz-1 || arr[mid+1]>val))
			return mid+1;
		else if(arr[mid]>val)
			h=mid-1;
		else
			l=mid+1;
	}
	return 0;
}
int main()
{
	ll n,m,l,x,y,v1,v2,w=mod,x1,x2,y1,y2,i,c1,c2,c3,c4,calc,ans,fin=-1;
	sl(n); sl(m); sl(l);
	rep(i,n)
	{
		sl(v1); sl(v2);
		query.pb(mp(v1, v2));
	}
	rep(i,m)
	{
		sl(x); sl(y);
		calc = w*x + y;
		arr.pb(calc);
		trace3(x,y,calc);
	}
	sort(arr.begin(), arr.end());
	rep(i,n)
	{
		x1=query[i].F; y1=query[i].S;
		x2=x1+l; y2=y1+l;
		c1=w*(x1-1)+(y1-1);
		c2=w*(x1-1)+(y1+l);
		c3=w*(x1+l)+(y1-1);
		c4=w*x2+y2;

		trace6(c4,c3,lower_bound(c4), lower_bound(c2), lower_bound(c3), lower_bound(c1));
		fin=max(fin,ans);
	}
	return 0;
}













