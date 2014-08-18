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

ll dp[1001][1001],arr[1001][1001];
int main()
{
	ll n,m,q,a,b,val,i,j,val1,val2,val3,ans=0;
	sl(n);
	sl(m);
	sl(q);
	rep(i,n)
		rep(j,m)
			arr[i][j]=0;
	rep(i,q)
	{
		sl(a);
		sl(b);
		sl(val);
		arr[a][b]+=val;
	}
	rep(i,m)
		dp[0][i]=arr[0][i];
	FOR(i,1,n)
	{
		rep(j,m)
		{
			val1=val2=val3=0;
			if(j!=0)
				val1=dp[i-1][j-1];
			val2=dp[i-1][j];
			if(j!=n-1)
				val3=dp[i-1][j+1];
			dp[i][j]=arr[i][j]+max(val1,max(val2,val3));
		}
	}
	rep(i,m)
	{
		ans=max(ans,dp[n-1][i]);
	}
	if(ans<0)
		return 1;
	pln(ans);
	return 0;
}













