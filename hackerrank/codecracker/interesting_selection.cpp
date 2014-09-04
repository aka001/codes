/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
	***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

ll arr[100006],brr[100006],dp[100006][2];
int main()
{
	ll t,n,maxit,i,calc;
	sl(t);
	while(t--)
	{
		maxit=-mod;
		sl(n);
		rep(i,n)
			sl(arr[i]);
		rep(i,n)
			sl(brr[i]);
		if(n==1)
		{
			printf("%lld\n",arr[i]);
			continue;
		}
		rep(i,n+1)
		{
			dp[i][0]=-mod;
			dp[i][1]=-mod;
		}
		dp[0][0]=arr[0];
		dp[0][1]=-mod;
		FOR(i,1,n)
		{
			dp[i][0]=dp[i-1][1]+arr[i];
			dp[i][1]=-brr[i]+max(dp[i-1][0],dp[i-1][1]);
			//printf("dp[%d][0]=%d dp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
		}
		//printf("%d\n",dp[n-1][1]);
		maxit=max(maxit,dp[n-1][1]);

		dp[0][0]=-brr[0];
		dp[0][1]=-brr[0];
		FOR(i,1,n)
		{
			dp[i][0]=dp[i-1][1]+arr[i];
			dp[i][1]=-brr[i]+max(dp[i-1][0],dp[i-1][1]);
		}
		calc=max(dp[n-1][1],dp[n-1][0]);
		maxit=max(maxit,calc);
		pln(maxit);
	}
	return 0;
}









