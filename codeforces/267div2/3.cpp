/*******************
  	Akash Agrawall
	IIIT HYDERABAD
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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll arr[5006],cum[5006],str[5006],vis[5002][5002],dp[5002][5002];
ll maxit=-1,ans,m,n;
ll recurseit(ll k,ll sum, ll l)
{
	ll i,ansit=-1;
	if(l>n-1)
	{
		dp[l][k]=0;
		vis[l][n-1]=1;
		return sum;
	}
	if(vis[l][k]==1)
	{
		//printf("l=%lld k=%lld dp=%lld\n",l,k,dp[l][k]);
		return sum+dp[l][k];
		//maxit=max(maxit,sum+dp[l][n-1]);
	}
	if(k==0)
	{
		printf("l=%lld sum=%lld\n",l,sum);
		return sum;
	}
	ansit=0;
	for(i=l;i<n;i++)
	{
		if(i+m<=n)
		{
		//	if(i==5)
		//	printf("i=%lld k=%lld sum=%lld\n",i,k,sum+str[i]);
			ansit=max(ansit,recurseit(k-1,sum+str[i],i+m));

		}
		else
			break;
	}
	if(l==3 && k==1)
		printf("l=%lld k=%lld ansit=%lld\n",l,k,ansit);
	vis[l][k]=1;
	if(ansit==0)
		dp[l][k]=0;
	else
		dp[l][k]=ansit-sum;
}
int main()
{
	ll k,val,val1,i,sum;
	sum=0;
	sl(n);
	sl(m);
	sl(k);
	rep(i,n)
	{
		sl(arr[i]);
		sum+=arr[i];
		cum[i]=sum;
	}
	rep(i,n)
	{
		if(i+m-1>=n)
			break;
		val=0;
		if(i!=0)
			val=cum[i-1];
		val1=cum[i+m-1];
		str[i]=val1-val;
		//printf("i=%d str[i]=%lld\n",i,str[i]);
	}
	recurseit(k,0,0);
	pln(dp[0][k]);
	return 0;
}










