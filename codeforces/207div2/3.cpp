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
vector<pair<pair<int,int>, int> > arr;
bool comp(pair<pair<int,int>, int> v1, pair<pair<int,int>, int> v2)
{
	if(v1.F.F==v2.F.F)
		return v1.F.S>=v2.F.S;
	return v1.F.F<=v2.F.F;
}
int ans[MAX];
int main()
{
	int n,m,i,v1,v2,v3,wit,prev,lit,rit,nlit,nrit;
	si(n); si(m);
	rep(i,m)
	{
		si(v1); si(v2); si(v3);
		arr.pb(mp(mp(v1,v2), v3));
	}
	sort(arr.begin(), arr.end(), comp);
	//rep(i,m)
	//	trace2(arr[i].F.F, arr[i].F.S);
	prev=0;
	wit=arr[0].S;
	lit=arr[0].F.F;
	rit=arr[0].F.S;
	FOR(i,1,m)
	{
		v1=lit;
		nlit=arr[i].F.F;
		nrit=arr[i].F.S;
		//trace6(i, lit, rit, nlit, nrit, wit);
		while(lit<nlit)
		{
			if(lit==wit)
			{
				if(lit==prev)
					ans[lit]=0;
				else
					ans[lit]=prev;
			}
			else
				ans[lit]=wit;
			lit++;
		}
		while(rit>nrit)
		{
			//trace3(rit, wit, prev);
			if(rit==wit)
			{
				if(rit==prev)
					ans[rit]=0;
				else
					ans[rit]=prev;
			}
			else
				ans[rit]=wit;
			rit--;
		}
		prev=wit;
		wit=arr[i].S;
	}
	while(lit<=rit)
	{
		if(lit==wit)
		{
			if(lit==prev)
				ans[lit]=0;
			else
				ans[lit]=prev;
		}
		else
			ans[lit]=wit;
		lit++;
	}
	FOR(i,1,n+1)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}













