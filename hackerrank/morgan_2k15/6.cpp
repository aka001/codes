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
#define MAX 10006
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
ll dp[MAX][301], wt[MAX],n,m,kit;
vector<ll> arr[MAX];
ll dfs(ll node, ll k)
{
	ll &ret = dp[node][k];
	if(ret!=-1)
		return ret;
	ret=wt[node];
	if(k>=1)
		ret=max(ret, wt[node]*m);
	ll calc,fin=-mod,i,sz,ch;
	sz=arr[node].size();
	//trace2(node, sz);
	rep(i,sz)
	{
		ch=arr[node][i];
		calc=wt[node]+dfs(ch, k);
		//trace2(node, ch);
		fin=max(fin, calc);
	}
	rep(i,sz)
	{
		ch=arr[node][i];
		if(k>=1)
		{
			calc=wt[node]*m+dfs(ch, k-1);
			fin=max(fin, calc);
		}
	}
	//trace2(node, ret);
	ret=max(ret, fin);
	return ret;
}
int main()
{
	ll t,v1,v2,i,ans,sz;
	sl(t);
	while(t--)
	{
		fill(dp, -1);
		ans=-mod;
		rep(i,MAX)
			arr[i].clear();
		sl(n); sl(m); sl(kit);
		rep(i,n)
		{
			sl(wt[i]);
		}
		rep(i,n-1)
		{
			sl(v1); sl(v2);
			arr[v1].pb(v2);
		}
		sz=arr[0].size();
		//trace1(sz);
		rep(i,n)
		{
			ans = max(ans, dfs(i,kit));
		}
		pln(ans);
	}
	return 0;
}













