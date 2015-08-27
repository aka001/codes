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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch[MAX];
ll cost[1111][2],n,m,x,y,arr[1111][1111];
int dp[2111][2111][2];
int solve(ll l, ll cnt, ll cit)
{
	int &ret=dp[l][cnt][cit];
	if(cit!=-1 && ret!=-1)
		return ret;
	else if(l==m)
	{
		ret=0;
		return ret;
	}
	else if(l>m)
	{
		ret=mod;
		return ret;
	}
	else
	{
		int i,val1,val2,v1,v2;
		ret=mod;
		FOR(i,x,y+1)
		{
			if(cit!=0)
			{
				val1=cost[l+i-1][0];
				if(l!=0)
					val1-=cost[l-1][0];
				v1=solve(l+i, cnt, 0);
				ret=min(ret, val1+v1);
			}
			if(cit!=1)
			{
				val2=cost[l+i-1][1];
				if(l!=0)
					val2-=cost[l-1][1];
				v2=solve(l+i, cnt, 1);
				ret=min(ret, val2+v2);
			}
		}
		return ret;
	}
}
int main()
{
	ll i,j,k,c0,c1,ans;
	sl(n); sl(m); sl(x); sl(y);
	memset(dp, -1, sizeof(dp));
	rep(i,n)
	{
		ss(ch);
		c0=c1=0;
		rep(j,m)
		{
			if(ch[j]=='#')
				arr[i][j]=1;
			else
				arr[i][j]=0;
		}
	}
	rep(i,m)
	{
		c0=c1=0;
		rep(j,n)
		{
			if(arr[j][i]==0)
				c1++;
			else
				c0++;
		}
		cost[i][0]=c0; cost[i][1]=c1;
	}
	FOR(i,1,m)
		rep(j,2)
			cost[i][j]+=cost[i-1][j];
	ans=solve(0,0,-1);
	pln(ans);
	return 0;
}
