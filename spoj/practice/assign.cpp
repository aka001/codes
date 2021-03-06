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

ll arr[100][100],dp1[1<<21],dp2[1<<21],fit[21];
int main()
{
	ll t,n,i,j,k,sum,cnt,c,ans,calc,cit;
	sl(t);
	trace1(t);
	while(t--)
	{
		rep(i,1<<21)
			dp1[i]=dp2[i]=0;
		sl(n);
		rep(i,n)
		{
			rep(j,n)
			{
				sl(arr[i][j]);
			}
		}
		rep(i,n)
		{
			rep(j,1<<n)
				dp2[j]=0;
			rep(j,n)
			{
				if(arr[i][j]==0)
					continue;
				fit[j]=1;
				rep(k,1<<n)
				{
					cit=1<<j;
					calc=k&cit;
					//trace4(i,j,k,calc);
					if( calc == 0 )
					{
						//trace3(i,j,k);
						cit=1<<j;
						calc=k|cit;
						//trace5(i,j,k,cit,calc);
						dp2[calc]=max(dp2[calc],1+dp1[k]);
					}
				}
			}
			rep(j,1<<n)
			{
				dp1[j]+=dp2[j];
				trace3(i,j,dp1[j]);
			}
			ans=0;calc=1;
		}	
		rep(j,n)
		{
			if(fit[j]==1)
			{
				ans+=calc;
			}
			calc*=2;
		}
		trace1(ans);
		pln(dp1[ans]);
	}
	return 0;
}









