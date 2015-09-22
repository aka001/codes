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
ll dp[1<<19][20],calc,n,m,k, sat[MAX], cnt[MAX],mit, trans[40][40];
ll compute(ll state, ll rec)
{
	if(rec!=-1)
	{
		if(dp[state][rec]!=-1)
			return dp[state][rec];
	}
	if(cnt[state]>m)
		return dp[state][rec]=mit;
	else if(cnt[state]==m)
		return dp[state][rec]=0;
	else if(state==calc-1)
		return 0;
	else
	{
		ll &ret=dp[state][rec];
		ll i,i1,val;
		rep(i,n)
		{
			if((state&(1<<i))==0)
			{
				i1=(state|(1<<i));
				val = sat[i];
				val+=trans[rec][i];
				ret = max(ret, val+compute(i1, i));
			}
		}
		return ret;
	}
}
inline ll countit(ll val)
{
	ll i,cit=0;
	rep(i,n)
		if((val&(1<<i))!=0)
			cit++;
	return cit;
}
int main()
{
	ll i,j,v1,v2,v3,fin=-1,ait;
	mit=mod*mod; mit*=-1;
	fill(dp, -1);
	sl(n); sl(m); sl(k);
	calc=1<<n;
	rep(i,n)
		sl(sat[i]);
	rep(i,k)
	{
		sl(v1); sl(v2); sl(v3);
		v1--; v2--;
		//trace2(v1, v2);
		trans[v1][v2]+=v3;
	}
	rep(i,calc)
	{
		cnt[i]=countit(i);
	}
	fin = compute(0,-1);
	pln(fin);
	return 0;
}
