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
ll dp[1002][1002], dp1[1002][1002], arr[1002][1002];
int main()
{
	ll n,i,j,k,ans=0;
	sl(n);
	getchar();
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			cin>>arr[i][j];
			//scanint(arr[i][j]);
			//trace3(i, j, n);
		}
	}
	FOR(i,1,n+1)
		FOR(j,1,n+1)
		{
			dp[i][j]=1;
		}
	ans+=n*n;
	ans%=mod;
	for(k=99; k>=1; k--)
	{
		memset(dp1, 0 ,sizeof(dp1));
		FOR(i,1,n+1)
		{
			FOR(j,1,n+1)
			{
				if(arr[i][j]!=k)
					continue;
				if(arr[i-1][j]>arr[i][j])
					dp[i][j]+=dp[i-1][j];
				if(arr[i+1][j]>arr[i][j])
					dp[i][j]+=dp[i+1][j];
				if(arr[i][j+1]>arr[i][j])
					dp[i][j]+=dp[i][j+1];
				if(arr[i][j-1]>arr[i][j])
					dp[i][j]+=dp[i][j-1];
				dp[i][j]%=mod;
			}
		}
	}
	ans=0;
	FOR(i,1,n+1)
		FOR(j,1,n+1)
		{
			ans+=dp[i][j];
			ans%=mod;
		}
	pln(ans);
	return 0;
}













